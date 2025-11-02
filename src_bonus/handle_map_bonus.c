/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:45:38 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/01 13:20:31 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_map(t_game *game, char **line, int *i, int fd)
{
	size_t	len;

	len = ft_strlen(*line);
	if (len > 0 && (*line)[len - 1] == '\n')
		(*line)[len - 1] = '\0';
	game->map[*i] = *line;
	(*i)++;
	*line = get_next_line(fd);
}

int	read_map(char *filename, t_game *game)
{
	char	*line;
	int		fd;
	int		i;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		error_close_game(game, "Cannot open file");
	game->map = malloc(sizeof(char *) * 1024);
	if (!game->map)
		error_close_game(game, "Memory allocation failed");
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		fill_map(game, &line, &i, fd);
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

void	fill_valid_map(char **map, int y, int x, t_game *game)
{
	if (y < 0 || y >= game->rows || x < 0 || x >= game->cols)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == 'C' || map[y][x] == 'E'
		|| map[y][x] == '0' || map[y][x] == 'P')
		map[y][x] = 'V';
	else
		return ;
	fill_valid_map(map, y + 1, x, game);
	fill_valid_map(map, y - 1, x, game);
	fill_valid_map(map, y, x + 1, game);
	fill_valid_map(map, y, x - 1, game);
}
