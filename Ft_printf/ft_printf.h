/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yakhadad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:27:12 by yakhadad          #+#    #+#             */
/*   Updated: 2023/12/06 19:27:33 by yakhadad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putnbr(int n, int *len);
void	ft_putstr(char *s, int *len);
void	ft_putchar(char c, int *len);
void	ft_putadrs(void *adrs, int *len);
void	ft_unsigned(unsigned int nb, int *len);
void	ft_putnbr_base(unsigned int nb, char *base, int *len);

#endif
