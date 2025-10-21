/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:56:15 by rdcm              #+#    #+#             */
/*   Updated: 2025/10/21 00:34:39 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_game(t_game *game, char **argv)
{
	if (!read_map(argv[1], game))
		return (0);
	if (!validate_map(game))
	{
		if (game->e_count > 1)
			ft_printf("Error: More than one Exit\n");
		else if (game->p_count > 1)
			ft_printf("Error: More than one Player\n");
		write(2, "Error: invalid map\n", 19);
		return (0);
	}
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: Fail to initialize MLX\n");
		return (0);
	}
	if (!load_images(game))
		return (0);
	game->win = mlx_new_window(game->mlx, game->tile_size * game->cols,
			game->tile_size * game->rows, "Map");
	return (1);
}
