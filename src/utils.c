/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 01:07:09 by rdcm              #+#    #+#             */
/*   Updated: 2025/10/29 21:45:09 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
