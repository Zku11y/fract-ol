NAME = fractol

SRC = src/fractol.c src/parse.c src/Mandelbrot.c \
	  src/julia.c src/burning_ship.c src/input.c \
	  src/misc.c

OBJ = $(SRC:.c=.o)

MLX_DIR = MLX42
MLX_LIB = $(MLX_DIR)/mlx42lib/libmlx42.a
MLX_INC = -I$(MLX_DIR)
LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
PRINTF_DIR = printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror $(MLX_INC) $(LIBFT_INC) $(PRINTF_INC)

LDFLAGS = -L$(MLX_DIR) -framework Cocoa -framework OpenGL -framework IOKit

$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB)
	cc $(SRC) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) -Iinclude -lglfw -L"/Users/mdakni/.brew/opt/glfw/lib/" -o $(NAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean $(NAME)
