NAME = fractol

SRC = src/fractol.c
OBJ = $(SRC:.c=.o)

MLX_DIR = minilibx
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror $(MLX_INC)

# Use LDFLAGS only in the linking step
LDFLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit

$(NAME): $(OBJ) $(MLX_LIB)
	$(CC) $(OBJ) $(LDFLAGS) -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
