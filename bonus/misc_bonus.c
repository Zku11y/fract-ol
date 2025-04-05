/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:55:19 by mdakni            #+#    #+#             */
/*   Updated: 2025/04/02 13:27:16 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol_bonus.h"

void	error_msg(void)
{
	ft_printf("\n\n");
	ft_printf("\e[1;31m╔═══════════════════════════\e[0m");
	ft_printf("\e[1;31m════════════════════════════════╗\e[0m\n");
	ft_printf("\e[1;31m║ ███████╗██████╗  █████╗ \e[0m");
	ft_printf("\e[1;31m ██████╗████████╗ ██████╗ ██╗     ║\e[0m\n");
	ft_printf("\e[1;31m║ ██╔════╝██╔══██╗██╔══██╗██╔\e[0m");
	ft_printf("\e[1;31m════╝╚══██╔══╝██╔═══██╗██║     ║\e[0m\n");
	ft_printf("\e[1;31m║ █████╗  ██████╔╝███████║██║\e[0m");
	ft_printf("\e[1;31m        ██║   ██║   ██║██║     ║\e[0m\n");
	ft_printf("\e[1;31m║ ██╔══╝  ██╔══██╗██╔══██║██║\e[0m");
	ft_printf("\e[1;31m        ██║   ██║   ██║██║     ║\e[0m\n");
	ft_printf("\e[1;31m║ ██║     ██║  ██║██║  ██║╚\e[0m");
	ft_printf("\e[1;31m██████╗   ██║   ╚██████╔╝███████╗║\e[0m\n");
	ft_printf("\e[1;31m║ ╚═╝     ╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝\e[0m");
	ft_printf("\e[1;31m   ╚═╝    ╚═════╝ ╚══════╝║\e[0m\n");
	ft_printf("\e[1;31m╚═════════════════════════\e[0m");
	ft_printf("\e[1;31m══════════════════════════════════╝\e[0m\n");
	ft_printf("\n\n");
	ft_printf("\e[1;31mInput Error...\e[0m\n\n");
	ft_printf("\e[1;32mCorrect Format :\e[0m\n");
	ft_printf("\n\e[1;32m./fractol_bonus mandelbrot\e[0m\n");
	ft_printf("\n\e[1;32m./fractol_bonus burning_ship\e[0m\n");
	ft_printf("\n\e[1;32m./fractol_bonus julia <r> <i>\e[0m\n");
	ft_printf("\n\e[1;32mr and i are floats between -2 and 2\e[0m\n");
	exit(EXIT_FAILURE);
}

void	calc_zoom_diff(t_mlx *mlx, int32_t x, int32_t y, double yd)
{
	double	mouse_cr;
	double	mouse_ci;

	mouse_cr = (((x / (double)WIDTH) * (REAL_MAX - REAL_MIN) + REAL_MIN)
			* mlx->zoom) + mlx->left_right;
	mouse_ci = (((y / (double)HEIGHT) * (IMG_MAX - IMG_MIN) + IMG_MIN)
			* mlx->zoom) + mlx->up_down;
	if (yd < 0)
		mlx->zoom *= 0.9;
	else
		mlx->zoom *= 1.1;
	mlx->left_right += (mouse_cr - ((((x / (double)WIDTH) * (REAL_MAX
							- REAL_MIN) + REAL_MIN) * mlx->zoom)
				+ mlx->left_right));
	mlx->up_down += (mouse_ci - ((((y / (double)HEIGHT) * (IMG_MAX - IMG_MIN)
						+ IMG_MIN) * mlx->zoom) + mlx->up_down));
}
