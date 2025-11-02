/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:42:52 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/02 19:51:24 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_tile(t_game *game, int x, int y)
{
	void	*img;
	char	tile_char;

	tile_char = game->map[y][x];
	mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
		x * game->tile_size, y * game->tile_size);
	if (tile_char == '1')
		img = game->img_wall;
	else if (tile_char == 'P')
	{
		img = game->img_player;
		game->player_x = x;
		game->player_y = y;
	}
	else if (tile_char == 'C')
		img = game->img_collectable;
	else if (tile_char == 'E')
		img = game->img_exit;
	else
		return ;
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * game->tile_size, y * game->tile_size);
}

void	render_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->rows)
	{
		j = 0;
		while (j < game->cols)
		{
			render_tile(game, j, i);
			j++;
		}
		i++;
	}
}

int	load_images(t_game *game)
{
	int	w;
	int	h;

	game->tile_size = 32;
	game->img_floor = mlx_xpm_file_to_image(game->mlx, FLOOR, &w, &h);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, WATER, &w, &h);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx, MEAT, &w, &h);
	game->img_player = mlx_xpm_file_to_image(game->mlx, PLAYER, &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, EXIT, &w, &h);
	if (!game->img_floor || !game->img_wall
		|| !game->img_collectable || !game->img_player)
	{
		return (0);
	}
	return (1);
}

void	update_map(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = 'P';
	render_map(game);
}
