/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:40:48 by mdakni            #+#    #+#             */
/*   Updated: 2024/12/03 10:13:41 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	putnbr(int n);
int		nbr_size(int a);
int		ft_printf(const char *num, ...);
int		handle_c(va_list args, const char **content);
int		handle_s(va_list args, const char **content);
int		handle_u(va_list args, const char **content);
int		handle_x(va_list args, const char **content);
int		handle_p(va_list args, const char **content);
int		handle_id(va_list args, const char **content);
int		handle_perc(const char **content);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr(const char *s, int c);
#endif