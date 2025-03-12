SRC = ft_printf.c ../libft/ft_strlen.c \
	handle_print.c ../libft/ft_putnbr_fd.c nbr_size.c \
	handle_hex.c putnbr.c \
	../libft/ft_putstr_fd.c handle_dec.c \
	../libft/ft_strchr.c

BSRC = bonus/ft_printf_bonus.c bonus/ft_strlen_bonus.c \
	bonus/handle_print_bonus.c bonus/ft_putnbr_fd_bonus.c bonus/nbr_size_bonus.c \
	bonus/handle_hex_bonus.c bonus/putnbr_bonus.c \
	bonus/ft_putstr_fd_bonus.c bonus/handle_dec_bonus.c \
	bonus/ft_strchr_bonus.c bonus/ft_flag_check_bonus.c

NAME = libftprintf.a
OBJS = $(SRC:.c=.o);
BOBJS = $(BSRC:.c=.o);
CC = cc
FLAGS = -Wall -Wextra -Werror

all:$(NAME)

$(NAME):$(OBJS)
	ar rcs $(NAME) $(OBJS)

bonus:$(OBJS) $(BOBJS)
	ar rcs $(NAME) $(OBJS) $(BOBJS)

%.o:%.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@

bonus/%.o:bonus/%.c bonus/ft_printf_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	rm -f $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: clean