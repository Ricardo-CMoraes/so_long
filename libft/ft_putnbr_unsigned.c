/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/03 23:06:09 by rdcm              #+#    #+#             */
/*   Updated: 2025/10/04 17:01:36 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_unsigned_int(unsigned int n, int fd)
{
	char	c;

	if (n >= 10)
	{
		put_unsigned_int(n / 10, fd);
		n = n % 10;
	}
	if (n < 10)
	{
		c = n + '0';
		write(fd, &c, 1);
	}
}

unsigned int	ft_putnbr_unsigned(unsigned int n, int fd)
{
	put_unsigned_int(n, fd);
	return (n_digits(n, 10));
}
