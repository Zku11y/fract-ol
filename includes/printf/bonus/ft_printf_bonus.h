/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdakni <mdakni@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:09:40 by mdakni            #+#    #+#             */
/*   Updated: 2024/12/02 16:14:59 by mdakni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <unistd.h>

typedef struct flag_struct
{
	int	tag;
	int	space;
	int	plus;
}		t_flags;

void		putnbr(int n);
int			nbr_size(int a);
int			ft_printf(const char *num, ...);
int			handle_c(va_list args, const char **content);
int			handle_s(va_list args, const char **content);
int			handle_u(va_list args, const char **content);
int			handle_x(va_list args, const char **content, t_flags flags);
int			handle_p(va_list args, const char **content);
int			handle_id(va_list args, const char **content, t_flags flags);
int			handle_perc(const char **content);
void		ft_putnbr_fd(int n, int fd);
t_flags		flag_check(const char **content, t_flags flag);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
#endif