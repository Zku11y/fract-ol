/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 23:23:53 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/29 14:59:27 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	*ptr;

	i = 0;
	ptr = NULL;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] == (char)c)
		ptr = &s[i];
	return ((char *)ptr);
}
