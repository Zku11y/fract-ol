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
// 5120 x 2880
# define WIDTH 800
# define HEIGHT 800
# define real_min -2
# define real_max 2
# define img_min -2
# define img_max 2
# define max_iter 100

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
    int width;
    int height;
    int flag;
}   t_mlx;

int parse(int ac, char **av);
void julia(mlx_image_t *image, t_mlx *mlx);
void burning_ship(mlx_image_t *image, t_mlx *mlx);
void burning_color(t_mlx *mlx, double iter);
void mandelbrot(mlx_image_t *image, t_mlx *mlx);
void color(t_mlx *mlx, double iter);
void color_2(t_mlx *mlx, double iter);
void error_msg();

#endif
