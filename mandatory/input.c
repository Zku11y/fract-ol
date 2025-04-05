/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:57:53 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/29 11:36:12 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	color_input(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_4)
		mlx->t_color = 1;
	else if (keydata.key == MLX_KEY_5)
		mlx->t_color = 2;
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	(void)xdelta;
	if (ydelta > 0)
		mlx->zoom *= 1.1;
	else if (ydelta < 0)
		mlx->zoom *= 0.9;
	if (mlx->flag == 1)
		mandelbrot(mlx->image, mlx);
	else if (mlx->flag == 2)
		julia(mlx->image, mlx);
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}

void	key_hook(mlx_key_data_t keydata, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			exit(EXIT_SUCCESS);
		color_input(keydata, mlx);
	}
	if (mlx->flag == 1)
		mandelbrot(mlx->image, mlx);
	else if (mlx->flag == 2)
		julia(mlx->image, mlx);
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
}
