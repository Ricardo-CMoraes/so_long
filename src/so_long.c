/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 14:48:59 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/01 14:14:44 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		status;

	ft_memset(&game, 0, sizeof(t_game));
	if (!check_arguments(argc, argv))
		return (1);
	status = init_game(&game, argv);
	if (!status)
		return (1);
	render_map(&game);
	mlx_hook(game.win, 17, 0, handle_close_win, &game);
	mlx_hook(game.win, 2, 1L << 0, key_press, &game);
	mlx_loop(game.mlx);
	return (cleanup_game(&game));
}
