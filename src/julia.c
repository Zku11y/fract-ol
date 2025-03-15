/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 23:34:52 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/15 15:50:01 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	mod_color(t_mlx *mlx, double iter)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	double		t;

	if (iter == mlx->max_iter)
	{
		mlx->color = 0x000000FF;
		return ;
	}
	t = iter / mlx->max_iter;
	r = (uint32_t)(t * mlx->r * t * 255);
	g = (uint32_t)(t * mlx->g * t * 255);
	b = (uint32_t)(t * mlx->b * t * 255);
	mlx->color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

void	get_color(t_mlx *mlx, int iter)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	double		t;

	if (iter == mlx->max_iter)
	{
		mlx->color = 0x000000FF;
		return ;
	}
	else
	{
		t = (double)iter / (double)mlx->max_iter;
		r = (uint32_t)(9 * (1 - t) * t * t * t * 255);
		g = (uint32_t)(15 * (1 - t) * (1 - t) * t * t * 255);
		b = (uint32_t)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		mlx->color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
	}
}

void	equation_julia(t_mlx *mlx)
{
	double	iter;
	double	temp;

	iter = 0;
	while (mlx->zr * mlx->zr + mlx->zi * mlx->zi < 5 && iter < mlx->max_iter)
	{
		temp = (mlx->zr * mlx->zr) - (mlx->zi * mlx->zi) + mlx->cr;
		mlx->zi = (2 * mlx->zr * mlx->zi) + mlx->ci;
		mlx->zr = temp;
		iter = iter + 0.8;
	}
	if (mlx->t_color == 1)
		mod_color(mlx, (double)iter);
	else
		burning_color(mlx, (double)iter);
}

void	julia(mlx_image_t *image, t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->cr = mlx->arg1;
	mlx->ci = mlx->arg2;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			mlx->zi = (((y / (double)HEIGHT) * (IMG_MAX - IMG_MIN) + IMG_MIN)
					* mlx->zoom) + mlx->up_down;
			mlx->zr = (((x / (double)WIDTH) * (REAL_MAX - REAL_MIN) + REAL_MIN)
					* mlx->zoom) + mlx->left_right;
			equation_julia(mlx);
			mlx_put_pixel(image, x, y, mlx->color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}

void	color_2(t_mlx *mlx, double iter)
{
	if (iter == mlx->max_iter)
		mlx->color = 0x0000FF;
	else
		mlx->color = (iter / mlx->max_iter) * (0xFFFFFF);
}
