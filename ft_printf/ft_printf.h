/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stuna <stuna@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:41:54 by stuna             #+#    #+#             */
/*   Updated: 2023/11/23 14:37:08 by stuna            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	print_adrs(unsigned long long ptr);
int	print_hex_s(unsigned int n);
int	print_hex_b(unsigned int n);
int	print_num(int n);
int	print_prcnt(void);
int	print_str(char *str);
int	print_unsgnd(unsigned int n);
int	putchar_printf(char c);

#endif
