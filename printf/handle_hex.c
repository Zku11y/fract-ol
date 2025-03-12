/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:40:58 by mdakni            #+#    #+#             */
/*   Updated: 2024/11/27 15:43:57 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rev_str(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (len >= 0)
		write(1, &str[len--], 1);
}

int	long_to_hex(unsigned long nbr)
{
	int		size;
	char	*hex;
	char	str[20];

	size = 0;
	if (nbr == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	hex = "0123456789abcdef";
	while (nbr > 0)
	{
		str[size] = hex[nbr % 16];
		nbr = nbr / 16;
		size++;
	}
	str[size] = '\0';
	ft_putstr_fd("0x", 1);
	rev_str(str);
	return (size + 2);
}

int	handle_x(va_list args, const char **content)
{
	int				size;
	char			*hex;
	char			str[20];
	unsigned int	nbr;

	size = 0;
	nbr = va_arg(args, unsigned int);
	if (**content == 'x')
		hex = "0123456789abcdef";
	else if (**content == 'X')
		hex = "0123456789ABCDEF";
	*(content) = *(content) + 1;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	while (nbr > 0)
	{
		str[size++] = hex[nbr % 16];
		nbr = nbr / 16;
	}
	str[size] = '\0';
	rev_str(str);
	return (size);
}

int	handle_p(va_list args, const char **content)
{
	void			*ptr;
	unsigned long	nbr;
	int				size;

	ptr = va_arg(args, void *);
	nbr = (unsigned long)ptr;
	size = long_to_hex(nbr);
	*(content) = *(content) + 1;
	return (size);
}
