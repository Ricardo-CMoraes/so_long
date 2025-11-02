/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:58:12 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/01 13:15:27 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_border(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->cols)
	{
		if (game->map[0][x] != '1' || game->map[game->rows - 1][x] != '1')
			return (0);
		x++;
	}
	y = 1;
	while (y < game->rows - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][game->cols - 1] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_valid_path(t_game *game)
{
	char	**temp_map;
	int		y;
	int		x;
	int		valid;

	valid = 1;
	temp_map = copy_map(game);
	if (!temp_map)
		return (0);
	fill_valid_map(temp_map, game->player_y, game->player_x, game);
	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (x < game->cols)
		{
			if (temp_map[y][x] == 'C' || temp_map[y][x] == 'E')
				valid = 0;
			x++;
		}
		y++;
	}
	free_map(temp_map, game->rows);
	return (valid);
}

int	check_character(t_game *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			c = game->map[y][x];
			if (!check_char(game, c, y, x))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	check_colums(t_game *game)
{
	int		y;
	int		x;

	y = 0;
	while (y < game->rows)
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != '\n')
		{
			x++;
		}
		if (x != game->cols)
			return (0);
		y++;
	}
	return (1);
}

int	validate_map(t_game *game)
{
	if (!check_colums(game))
		error_close_game(game, "Map is not rectangular");
	if (!check_character(game))
		error_close_game(game, "Invalid character in map");
	if (!(game->p_count == 1 && game->e_count == 1 && game->c_count >= 1))
		return (0);
	if (!check_border(game))
		error_close_game(game, "Map is not surrounded by walls");
	if (!check_valid_path(game))
		error_close_game(game, "Map is unsolvable");
	return (1);
}
