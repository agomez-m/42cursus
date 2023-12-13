/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agomez-m <agomez-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:03:10 by agomez-m          #+#    #+#             */
/*   Updated: 2023/12/13 18:17:28 by agomez-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include "get_next_line.h"

int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_digit(long n, int base);
int		ft_print_digitx(long n, int base);
int		ft_print_u(unsigned int n);
int		ft_putpoi(unsigned long long ptr);
int		ft_printf(const char *format, ...);

#endif