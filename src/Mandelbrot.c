/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:48:29 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/15 17:06:07 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <stdio.h>

void	color(t_mlx *mlx, double iter)
{
	u_int32_t	r;
	u_int32_t	g;
	u_int32_t	b;

	if (iter >= (double)mlx->max_iter)
	{
		mlx->color = 0x000000FF;
		return ;
	}
	r = (u_int32_t)fmin(fmax(sin(0.1 * iter + 1) * 127 + 128, 0), 255);
	g = (u_int32_t)fmin(fmax(sin(0.1 * iter + 2) * 127 + 128, 0), 255);
	b = (u_int32_t)fmin(fmax(sin(0.1 * iter + 5) * 127 + 128, 0), 255);
	mlx->color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

void	equation(t_mlx *mlx)
{
	double	iter;
	double	temp;

	mlx->zi = 0;
	mlx->zr = 0;
	iter = 0;
	while (mlx->zr * mlx->zr + mlx->zi * mlx->zi < 5 && iter < mlx->max_iter)
	{
		temp = (mlx->zr * mlx->zr) - (mlx->zi * mlx->zi) + mlx->cr;
		mlx->zi = (2 * mlx->zr * mlx->zi) + mlx->ci;
		mlx->zr = temp;
		iter = iter + 0.5;
	}
	if (mlx->t_color == 1)
		mod_color(mlx, (double)iter);
	else
		burning_color(mlx, (double)iter);
}

void	mandelbrot(mlx_image_t *image, t_mlx *mlx)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		mlx->ci = (((y / (double)HEIGHT) * (IMG_MAX - IMG_MIN) + IMG_MIN)
				* mlx->zoom) + mlx->up_down;
		x = 0;
		while (x < WIDTH)
		{
			mlx->cr = (((x / (double)WIDTH) * (REAL_MAX - REAL_MIN) + REAL_MIN)
					* mlx->zoom) + mlx->left_right;
			equation(mlx);
			mlx_put_pixel(image, x, y, mlx->color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}
