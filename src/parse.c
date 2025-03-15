/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 12:29:13 by mdakni            #+#    #+#             */
/*   Updated: 2025/03/15 15:55:42 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	parse(int ac, char **av)
{
	if (ac == 2 && ft_strncmp(av[1], "mandelbrot", 10) == 0)
		return (1);
	else if (ac == 4 && ft_strncmp(av[1], "julia", 5) == 0)
		return (2);
	else if (ac == 2 && ft_strncmp(av[1], "burning_ship", 12) == 0)
		return (3);
	return (error_msg(), -1);
}

void	check_args(char **av, t_mlx *mlx)
{
	mlx->cr = ft_atof(av[2]);
	mlx->ci = ft_atof(av[3]);
	if (mlx->cr > 2.0)
		mlx->cr = 2.0;
	else if (mlx->cr < -2.0)
		mlx->cr = -2.0;
	if (mlx->ci > 2.0)
		mlx->ci = 2.0;
	else if (mlx->ci < -2.0)
		mlx->ci = -2.0;
	mlx->arg1 = mlx->cr;
	mlx->arg2 = mlx->ci;
}

double	decimal_value(const char *str, int i)
{
	double	decimal_mult;
	double	result;

	i++;
	result = 0.0;
	decimal_mult = 1.0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		decimal_mult *= 10;
		result = result + ((str[i] - '0') / decimal_mult);
		i++;
	}
	if (str[i] != '\0')
		error_msg();
	return (result);
}

double	ft_atof(const char *str)
{
	int		i;
	double	result;
	double	sign;

	i = 0;
	result = 0.0;
	sign = 1.0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1.0;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		error_msg();
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	if (str[i] != '\0' && str[i] != '.')
		error_msg();
	if (str[i] == '.')
		result += decimal_value(str, i++);
	result *= sign;
	return (result);
}
