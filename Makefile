NAME = fractol

BNAME = fractol_bonus

SRC = mandatory/fractol.c mandatory/parse.c mandatory/Mandelbrot.c \
	  mandatory/julia.c mandatory/input.c \
	  mandatory/misc.c

BSRC = bonus/fractol_bonus.c bonus/parse_bonus.c bonus/Mandelbrot_bonus.c \
	  bonus/julia_bonus.c bonus/burning_ship_bonus.c bonus/input_bonus.c \
	  bonus/misc_bonus.c

OBJ = $(SRC:.c=.o)
BOBJ = $(BSRC:.c=.o)

MLX_DIR = includes/MLX42
MLX_LIB = $(MLX_DIR)/mlx42lib/libmlx42.a
MLX_INC = -I$(MLX_DIR)
LIBFT_DIR = includes/libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBFT_INC = -I$(LIBFT_DIR)
PRINTF_DIR = includes/printf
PRINTF_LIB = $(PRINTF_DIR)/libftprintf.a
PRINTF_INC = -I$(PRINTF_DIR)

CC = cc
CFLAGS = -Wall -Wextra -Werror $(MLX_INC) $(LIBFT_INC) $(PRINTF_INC)

LDFLAGS = -L$(MLX_DIR) -framework Cocoa -framework OpenGL -framework IOKit

all:$(NAME)

bonus:$(BNAME)

$(NAME): $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB)
	cc $(OBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) -Iinclude -lglfw -L"/Users/mdakni/.brew/opt/glfw/lib/" -o $(NAME)

$(BNAME): $(BOBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB)
	cc $(BOBJ) $(MLX_LIB) $(LIBFT_LIB) $(PRINTF_LIB) -Iinclude -lglfw -L"/Users/mdakni/.brew/opt/glfw/lib/" -o $(BNAME)

$(MLX_LIB):
	make -C $(MLX_DIR)

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(PRINTF_LIB):
	make -C $(PRINTF_DIR)

mandatory/%.o: mandatory/%.c mandatory/fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus/%.o: bonus/%.c bonus/fractol_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(BOBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -f $(BNAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean

re: fclean $(NAME)

.PHONY: clean