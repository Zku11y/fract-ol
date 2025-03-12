/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_dec_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:40:53 by mdakni            #+#    #+#             */
/*   Updated: 2024/12/02 16:14:33 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	nbr_u_size(unsigned int a)
{
	int	size;

	size = 0;
	while (a / 10 > 0)
	{
		a = a / 10;
		size++;
	}
	return (size + 1);
}

void	putnbr_u(unsigned int n)
{
	char	chr;
	long	nbr;

	nbr = n;
	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= 10)
		putnbr_u(nbr / 10);
	chr = (nbr % 10) + '0';
	write(1, &chr, 1);
}

int	handle_u(va_list args, const char **content)
{
	unsigned int	a;

	a = va_arg(args, unsigned int);
	putnbr_u(a);
	*(content) = *(content) + 1;
	return (nbr_u_size(a));
}

int	handle_id(va_list args, const char **content, t_flags flagsss)
{
	int	a;
	int	flag_size;

	flag_size = 0;
	a = va_arg(args, int);
	if ((flagsss.plus) && (a >= 0))
	{
		write(1, "+", 1);
		flag_size++;
	}
	else if ((flagsss.space) && (a >= 0) && (!flagsss.plus))
	{
		write(1, " ", 1);
		flag_size++;
	}
	putnbr(a);
	*(content) = *(content) + 1;
	return (nbr_size(a) + flag_size);
}
