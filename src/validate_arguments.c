/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:54:19 by rdcm              #+#    #+#             */
/*   Updated: 2025/10/18 20:54:44 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_arguments(int argc, char **argv)
{
	char 	*map_file;
	int		len;
	
	if (argc != 2)
    {
        ft_printf("Use: %s arquivo.ber\n", argv[0]);
        return (0);
	}
	map_file = argv[1];
    len = ft_strlen(map_file);
    if (len < 4 || ft_strncmp(map_file + len - 4, ".ber", 4) != 0)
    {
        ft_printf("Erro: Arquivo inválido, precisa ter extensão .ber\n");
        return (0);
    }
	return (1);	
}