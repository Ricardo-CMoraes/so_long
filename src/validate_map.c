/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 15:58:12 by rdcm              #+#    #+#             */
/*   Updated: 2025/10/21 00:21:54 by rdcm             ###   ########.fr       */
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
		{
			ft_printf("Error: O mapa não esta cercado por paredes.\n");
			return (0);
		}
		x++;
	}
	y = 1;
	while (y < game->rows - 1)
	{
		if (game->map[y][0] != '1' || game->map[y][game->cols - 1] != '1')
		{
			ft_printf("Error: O mapa não esta cercado por paredes.\n");
			return (0);
		}
		y++;
	}
	return (1);
}

void	flood_fill(char **map, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->rows || x < 0 || x >= game->cols)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E'
		|| map[y][x] == '0' || map[y][x] == 'P')
		map[y][x] = 'V';
	else
		return ;
	flood_fill(map, y + 1, x, game);
	flood_fill(map, y - 1, x, game);
	flood_fill(map, y, x + 1, game);
	flood_fill(map, y, x - 1, game);
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
	flood_fill(temp_map, game->player_y, game->player_x, game);
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
			if (c == 'P')
			{
				game->p_count++;
				game->player_y = y;
				game->player_x = x;
			}
			else if (c == 'E')
				game->e_count++;
			else if (c == 'C')
				game->c_count++;
			if (c != 'P' && c != 'E' && c != 'C' && c != '1' && c != '0')
				return (0);
			x++;
		}
		if (x != game->cols)
			return (0);
		y++;
	}
	if (game->p_count == 1 && game->e_count == 1 && game->c_count >= 1)
		return (1);
	return (0);
}

int	validate_map(t_game *game)
{
	if (!check_character(game))
		return (0);
	if (!check_border(game))
		return (0);
	if (!check_valid_path(game))
		return (0);
	return (1);
}
