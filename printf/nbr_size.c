/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:44:36 by mdakni            #+#    #+#             */
/*   Updated: 2024/12/03 10:12:48 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nbr_size(int a)
{
	int		size;
	int		sign;
	long	nbr;

	size = 0;
	sign = 0;
	nbr = a;
	if (nbr < 0)
	{
		sign = 1;
		nbr = nbr * -1;
	}
	while (nbr / 10 > 0)
	{
		nbr = nbr / 10;
		size++;
	}
	return ((size + 1) + sign);
}
