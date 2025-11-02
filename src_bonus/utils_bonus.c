/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:07:09 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/02 18:11:45 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_char(t_game *game, char c, int y, int x)
{
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
	return (1);
}

void	print_error(char *msg)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(msg, 2);
	ft_putstr_fd("\n", 2);
}

void	print_moviments(t_game *game)
{
	char	*moviments;
	char	*phrase;
	int		x_pos;
	int		y_pos;
	int		color;

	moviments= ft_itoa(game->move_count); 
	phrase = ft_strjoin("Movimentos: ", moviments);
	x_pos = 5;
	y_pos = 15;
	color = 0xFFFFFF;
	mlx_string_put(game->mlx, game->win, x_pos, y_pos, color, phrase);
	free(moviments);
	free(phrase);
}