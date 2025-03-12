/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:29:13 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/12 13:32:44 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int parse(int ac, char **av)
{
    if(ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
        return(1);
    else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
        return (2);
    return(0);
}
void error_msg()
{
    ft_printf("\e[1;31mInput Error...\e[0m\n\n");
    ft_printf("\e[1;32mCorrect Format :\n\n./fractol mandelbrot\n\n./fractol julia <width> <height>\e[0m\n");
    exit(EXIT_FAILURE);
}