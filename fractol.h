#ifndef FRACTOL_H
#define FRACTOL_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include "printf/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>

# define WIDTH 800
# define HEIGHT 600
# define real_min -2
# define real_max 2
# define img_min -1.5
# define img_max 1.5
# define max_iter 1000

typedef struct mlx_struct
{
    void *mlx;
    mlx_image_t *image;
    double zr;
    double zi;
    double cr;
    double ci;
    int color;
    double zoom;
    double left_right;
    double up_down;
}   t_mlx;

int parse(int ac, char **av);
void mandelbrot(mlx_image_t *image, t_mlx *mlx);
void error_msg();

#endif
