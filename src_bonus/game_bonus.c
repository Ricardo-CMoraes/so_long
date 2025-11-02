/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:56:15 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/01 13:31:48 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char **argv)
{
	if (!read_map(argv[1], game))
		return (0);
	if (!validate_map(game))
	{
		if (game->p_count > 1)
			error_close_game(game, "Too many players");
		else if (game->e_count > 1)
			error_close_game(game, "Too many exits");
		else if (game->p_count == 0 || game->e_count == 0 || game->c_count == 0)
			error_close_game(game, "Missing required elements");
		return (0);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
		error_close_game(game, "Failed to initialize MLX");
	if (!load_images(game))
		error_close_game(game, "Failed to load texture");
	game->win = mlx_new_window(game->mlx, game->tile_size * game->cols,
			game->tile_size * game->rows, "Map");
	return (1);
}
