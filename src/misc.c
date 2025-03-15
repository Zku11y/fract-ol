/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 13:55:19 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/15 17:01:46 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	leak_check(void)
{
	system("leaks fractol");
}

void	error_msg(void)
{
	ft_printf("\e[1;31mInput Error...\e[0m\n\n");
	ft_printf("\e[1;32mCorrect Format :\e[0m\n");
	ft_printf("\n\e[1;32m./fractol mandelbrot\e[0m\n");
	ft_printf("\n\e[1;32m./fractol julia <r> <i>\e[0m\n");
	ft_printf("\n\e[1;32mr and i are floats between -2 and 2\e[0m\n");
	ft_printf("\n\e[1;32m./fractol burning_ship\e[0m\n");
	exit(EXIT_FAILURE);
}
