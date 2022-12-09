/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 10:53:55 by syluiset          #+#    #+#             */
/*   Updated: 2022/11/22 11:42:54 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

# define LOWER_BASE_16	"0123456789abcdef"
# define UPPER_BASE_16X	"0123456789ABCDEF"

int		ft_printf(const char *format, ...);

int		ft_putchar(int c);

int		ft_putstr(char *str);

void	ft_putnbr_10(int nb, int *nbdigit);

void	ft_putunbr_10(unsigned int nb, int *nbdigit);

void	ft_putpointer(size_t nb, int *nbdigit);

void	ft_putnbr_16_low(unsigned int nb, int *nbdigit);

void	ft_putnbr_16_up(unsigned int nb, int *nbdigit);

#endif
