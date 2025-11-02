NAME = so_long
NAME_BONUS = so_long_bonus

CC = cc
CFLAGS = -g -Wall -Wextra -Werror -Imlx_linux -Ilibft -Iincludes

SRC = src/so_long.c \
		src/clear.c \
		src/render_map.c\
		src/handle_map.c\
		src/validate_arguments.c\
		src/game.c\
		src/interaction.c\
		src/validate_map.c\
		src/utils.c

SRC_BONUS = src_bonus/so_long_bonus.c \
		src_bonus/clear_bonus.c \
		src_bonus/render_map_bonus.c\
		src_bonus/handle_map_bonus.c\
		src_bonus/validate_arguments_bonus.c\
		src_bonus/game_bonus.c\
		src_bonus/interaction_bonus.c\
		src_bonus/validate_map_bonus.c\
		src_bonus/utils_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = mlx_linux

MLX_FLAGS = -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS) $(LIBFT)
	$(CC) $(OBJ_BONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	make fclean -C $(LIBFT_DIR)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re
