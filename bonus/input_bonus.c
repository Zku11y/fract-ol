/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:57:53 by mdakni            #+#    #+#             */
/*   Updated: 2025/04/02 13:13:15 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	zoom_input(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_KP_SUBTRACT)
		mlx->zoom *= 1.1;
	else if (keydata.key == MLX_KEY_KP_ADD)
		mlx->zoom *= 0.9;
}

void	move_input(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_LEFT || keydata.key == MLX_KEY_A)
		mlx->left_right = (mlx->left_right - 0.1 * mlx->zoom);
	else if (keydata.key == MLX_KEY_RIGHT || keydata.key == MLX_KEY_D)
		mlx->left_right = (mlx->left_right + 0.1 * mlx->zoom);
	else if (keydata.key == MLX_KEY_UP || keydata.key == MLX_KEY_W)
		mlx->up_down = (mlx->up_down + 0.1 * mlx->zoom);
	else if (keydata.key == MLX_KEY_DOWN || keydata.key == MLX_KEY_S)
		mlx->up_down = (mlx->up_down - 0.1 * mlx->zoom);
	else if (keydata.key == MLX_KEY_N)
		mlx->max_iter++;
	else if (keydata.key == MLX_KEY_M && mlx->max_iter > 0)
		mlx->max_iter--;
}

void	color_input(mlx_key_data_t keydata, t_mlx *mlx)
{
	if (keydata.key == MLX_KEY_4)
		mlx->t_color = 1;
	else if (keydata.key == MLX_KEY_5)
		mlx->t_color = 2;
	else if (keydata.key == MLX_KEY_Y)
		mlx->r++;
	else if (keydata.key == MLX_KEY_U)
		mlx->g++;
	else if (keydata.key == MLX_KEY_I)
		mlx->b++;
	else if (keydata.key == MLX_KEY_H && mlx->r > 0)
		mlx->r--;
	else if (keydata.key == MLX_KEY_J && mlx->g > 0)
		mlx->g--;
	else if (keydata.key == MLX_KEY_L && mlx->b > 0)
		mlx->b--;
}

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_mlx	*mlx;
	int32_t	mouse_x;
	int32_t	mouse_y;

	(void)xdelta;
	mlx = (t_mlx *)param;
	mlx_get_mouse_pos(mlx->mlx, &mouse_x, &mouse_y);
	calc_zoom_diff(mlx, mouse_x, mouse_y, ydelta);
	if (mlx->flag == 1)
		mandelbrot(mlx->image, mlx);
	else if (mlx->flag == 2)
		julia(mlx->image, mlx);
	else
		burning_ship(mlx->image, mlx);
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
	put_string(mlx);
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
		zoom_input(keydata, mlx);
		move_input(keydata, mlx);
	}
	if (mlx->flag == 1)
		mandelbrot(mlx->image, mlx);
	else if (mlx->flag == 2)
		julia(mlx->image, mlx);
	else
		burning_ship(mlx->image, mlx);
	mlx_image_to_window(mlx->mlx, mlx->image, 0, 0);
	put_string(mlx);
}
