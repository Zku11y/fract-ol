/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 00:45:51 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/29 11:39:41 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	burning_color(t_mlx *mlx, double iter)
{
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;
	double		t;

	if (iter >= mlx->max_iter)
	{
		mlx->color = 0x000000FF;
		return ;
	}
	t = iter / mlx->max_iter;
	r = (uint32_t)(mlx->r * (1 - t) * t * t * t * 255);
	g = (uint32_t)(mlx->g * (1 - t) * (1 - t) * t * t * 255);
	b = (uint32_t)(mlx->b * (1 - t) * (1 - t) * (1 - t) * t * 255);
	mlx->color = (r << 24) | (g << 16) | (b << 8) | 0xFF;
}

void	burning_equation(t_mlx *mlx)
{
	double	iter;
	double	temp;

	mlx->zi = 0;
	mlx->zr = 0;
	iter = 0;
	while (mlx->zr * mlx->zr + mlx->zi * mlx->zi < 5 && iter < mlx->max_iter)
	{
		mlx->zr = fabs(mlx->zr);
		mlx->zi = fabs(mlx->zi);
		temp = (mlx->zr * mlx->zr) - (mlx->zi * mlx->zi) + mlx->cr;
		mlx->zi = (2 * mlx->zr * mlx->zi) + mlx->ci;
		mlx->zr = temp;
		iter = iter + 0.2;
	}
	if (mlx->t_color == 1)
		mod_color(mlx, (double)iter);
	else
		burning_color(mlx, (double)iter);
}

void	burning_ship(mlx_image_t *image, t_mlx *mlx)
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
			burning_equation(mlx);
			mlx_put_pixel(image, x, y, mlx->color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}
