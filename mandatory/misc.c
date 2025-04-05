/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:55:19 by mdakni            #+#    #+#             */
/*   Updated: 2025/04/02 13:18:17 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
	ft_printf("\n\e[1;32m./fractol mandelbrot\e[0m\n");
	ft_printf("\n\e[1;32m./fractol julia <r> <i>\e[0m\n");
	ft_printf("\n\e[1;32mr and i are floats between -2 and 2\e[0m\n");
	exit(EXIT_FAILURE);
}

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
