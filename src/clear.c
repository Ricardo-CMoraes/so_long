/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:13:38 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/02 19:50:49 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	cleanup_game(t_game *game)
{
	if (game->mlx)
	{
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->img_floor)
			mlx_destroy_image(game->mlx, game->img_floor);
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_collectable)
			mlx_destroy_image(game->mlx, game->img_collectable);
		if (game->img_exit)
			mlx_destroy_image(game->mlx, game->img_exit);
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free_map(game->map, game->rows);
	return (0);
}

int	error_close_game(t_game *game, char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
	cleanup_game(game);
	exit(EXIT_FAILURE);
}
