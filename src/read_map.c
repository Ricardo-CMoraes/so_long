/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:45:38 by rdcm              #+#    #+#             */
/*   Updated: 2025/10/20 23:49:20 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(char *filename, t_game *game)
{
	char	*line;
	int		fd;
	int		i;
	size_t	len;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	game->map = malloc(sizeof(char *) * 1024);
	if (!game->map)
		return (0);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		len = ft_strlen(line);
		if (len > 0 && line[len - 1] == '\n')
			line[len - 1] = '\0';
		game->map[i] = line;
		i++;
		line = get_next_line(fd);
	}
	game->map[i] = NULL;
	close(fd);
	game->rows = i;
	if (i > 0)
		game->cols = ft_strlen(game->map[0]);
	return (1);
}

char	**copy_map(t_game *game)
{
	char	**temp_map;
	int		i;

	temp_map = malloc(sizeof(char *) * game->rows);
	if (!temp_map)
		return (NULL);
	i = 0;
	while (i < game->rows)
	{
		temp_map[i] = ft_strdup(game->map[i]);
		if (!temp_map[i])
		{
			free_map(temp_map, game->rows);
			return (NULL);
		}
		i++;
	}
	return (temp_map);
}
