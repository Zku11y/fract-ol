/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:09:23 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/15 17:12:23 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"
#include <time.h>

void	fractol(t_mlx *mlx)
{
	mlx->max_iter = 18;
	mlx->zoom = 1.0;
	mlx->left_right = 0;
	mlx->up_down = 0;
	mlx->r = 10;
	mlx->g = 5;
	mlx->b = 3;
	mlx->image = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	mlx_scroll_hook(mlx->mlx, scroll_hook, mlx);
	mlx_key_hook(mlx->mlx, key_hook, mlx);
	mlx->t_color = 2;
	if (mlx->flag == 1)
		mandelbrot(mlx->image, mlx);
	else if (mlx->flag == 2)
		julia(mlx->image, mlx);
	else
		burning_ship(mlx->image, mlx);
}

void	parse_check(int ac, char **av, t_mlx *mlx)
{
	mlx->flag = 0;
	if (parse(ac, av) == 1)
	{
		mlx->mlx = mlx_init(WIDTH, HEIGHT, "Mandelbrot", true);
		mlx->flag = 1;
	}
	else if (parse(ac, av) == 2)
	{
		check_args(av, mlx);
		mlx->mlx = mlx_init(WIDTH, HEIGHT, "Julia", true);
		mlx->flag = 2;
	}
	else if (parse(ac, av) == 3)
	{
		mlx->mlx = mlx_init(WIDTH, HEIGHT, "Burning_ship", true);
		mlx->flag = 3;
	}
}

int	main(int ac, char **av)
{
	t_mlx	mlx;

	atexit(leak_check);
	parse_check(ac, av, &mlx);
	fractol(&mlx);
	mlx_loop(mlx.mlx);
	if (mlx.image)
		mlx_delete_image(mlx.mlx, mlx.image);
	if (mlx.mlx)
		mlx_terminate(mlx.mlx);
	return (0);
}
