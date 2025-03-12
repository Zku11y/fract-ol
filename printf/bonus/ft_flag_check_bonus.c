/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_check_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 14:59:03 by mdakni            #+#    #+#             */
/*   Updated: 2024/12/02 16:14:16 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

t_flags	flag_check(const char **content, t_flags flag)
{
	while (**content == ' ' || **content == '+' || **content == '#')
	{
		if (**content == ' ')
			flag.space = 1;
		else if (**content == '+')
			flag.plus = 1;
		else if (**content == '#')
			flag.tag = 1;
		*(content) = *(content) + 1;
	}
	return (flag);
}
