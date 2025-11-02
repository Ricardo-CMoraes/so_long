/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdcm <rdcm@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:14:37 by rdcm              #+#    #+#             */
/*   Updated: 2025/11/02 18:55:34 by rdcm             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <errno.h> 

# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define LEFT_KEY 65361
# define DOWN_KEY 65364
# define RIGHT_KEY 65363

# define FLOOR "./tiles/path_tile32.xpm"
# define WATER "./tiles/water_tile32.xpm"
# define MEAT "./tiles/Meat32_3.xpm"
# define PLAYER "./tiles/player32.xpm"
# define EXIT "./tiles/exit_32.xpm"

# define ERR_ARG1 "Invalid arguments."
# define ERR_ARG2 "Invalid extension. Expected: '.ber'"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		rows;
	int		cols;
	int		tile_size;
	void	*img_floor;
	void	*img_wall;
	void	*img_collectible;
	void	*img_player;
	void	*img_exit;
	int		player_x;
	int		player_y;
	int		collectible_count;
	int		move_count;
	int		p_count;
	int		e_count;
	int		c_count;
}				t_game;

int		init_game(t_game *game, char **argv);

void	render_tile(t_game *game, int x, int y);
void	render_map(t_game *game);
int		load_images(t_game *game);
void	update_map(t_game *game, int new_x, int new_y);

int		read_map(char *filename, t_game *game);
char	**copy_map(t_game *game);
void	fill_valid_map(char **map, int y, int x, t_game *game);

void	free_map(char **map, int rows);
int		cleanup_game(t_game *game);
int		error_close_game(t_game *game, char *msg);

int		check_arguments(int argc, char **argv);

int		handle_close_win(t_game *game);
void	try_move(t_game *game, int new_x, int new_y);
int		key_press(int keycode, t_game *game);

int		check_border(t_game *game);
int		check_valid_path(t_game *game);
int		check_character(t_game *game);
int		validate_map(t_game *game);
int		check_colums(t_game *game);

int		check_char(t_game *game, char c, int y, int x);
void	print_error(char *msg);
void	print_moviments(t_game *game);

#endif
