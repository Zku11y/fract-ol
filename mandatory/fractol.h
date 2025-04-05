/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 15:47:47 by mdakni            #+#    #+#             */
/*   Updated: 2025/04/02 13:52:20 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../includes/MLX42/include/MLX42/MLX42.h"
# include "../includes/libft/libft.h"
# include "../includes/printf/ft_printf.h"
# define WIDTH 800
# define HEIGHT 800
# define REAL_MIN -2
# define REAL_MAX 2
# define IMG_MIN -2
# define IMG_MAX 2

typedef struct mlx_struct
{
	void		*mlx;
	int			max_iter;
	mlx_image_t	*image;
	double		zr;
	double		zi;
	double		cr;
	double		ci;
	double		arg1;
	double		arg2;
	int			color;
	int			t_color;
	double		zoom;
	double		left_right;
	double		up_down;
	int			flag;
	char		*real;
	char		*img;
	int32_t		r;
	int32_t		g;
	int32_t		b;
}				t_mlx;

int				parse(int ac, char **av);
void			julia(mlx_image_t *image, t_mlx *mlx);
void			burning_color(t_mlx *mlx, double iter);
void			mandelbrot(mlx_image_t *image, t_mlx *mlx);
void			mod_color(t_mlx *mlx, double iter);
double			ft_atof(const char *str);
void			error_msg(void);
void			check_args(char **av, t_mlx *mlx);
void			key_hook(mlx_key_data_t keydata, void *param);
void			scroll_hook(double xdelta, double ydelta, void *param);
#endif
