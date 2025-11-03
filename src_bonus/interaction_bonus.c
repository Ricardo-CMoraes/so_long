/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interaction_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 23:54:56 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/02 22:16:43 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_close_win(t_game *game)
{
	cleanup_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

void	try_move(t_game *game, int new_x, int new_y)
{
	char	next_tile;

	next_tile = game->map[new_y][new_x];
	if (next_tile == '1' || next_tile == 'E')
	{
		if (next_tile == 'E' && game->c_count == 0)
		{
			ft_printf("Congratulations! You won in %d movements!\n",
				game->move_count + 1);
			handle_close_win(game);
		}
		return ;
	}
	game->move_count++;
	ft_printf("Movements: %d\n", game->move_count);
	if (next_tile == 'C')
		game->c_count--;
	if (next_tile == 'X')
	{
		ft_printf("You were caught!\n");
		handle_close_win(game);
	}
	update_map(game, new_x, new_y);
	print_moviments(game);
}

int	check_key_pressed(int keycode)
{
	if (keycode == W_KEY || keycode == S_KEY || keycode == A_KEY
		|| keycode == D_KEY || keycode == UP_KEY || keycode == DOWN_KEY
		|| keycode == LEFT_KEY || keycode == RIGHT_KEY)
		return (1);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	int	next_x;
	int	next_y;

	next_x = game->player_x;
	next_y = game->player_y;
	if (keycode == ESC_KEY)
		handle_close_win(game);
	else if (keycode == W_KEY || keycode == UP_KEY)
		next_y -= 1;
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		next_y += 1;
	else if (keycode == A_KEY || keycode == LEFT_KEY)
		next_x -= 1;
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		next_x += 1;
	if (next_x < 0 || next_x >= game->cols
		|| next_y < 0 || next_y >= game->rows)
	{
		ft_printf("Outside the map's boundaries");
		return (0);
	}
	if (check_key_pressed(keycode))
		try_move(game, next_x, next_y);
	return (0);
}
