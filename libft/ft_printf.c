/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:36:33 by alfreire          #+#    #+#             */
/*   Updated: 2024/07/12 13:18:37 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_format(va_list args, const char *specifier, int *count)
{
	if (*specifier == 'c')
		ftprint_char(va_arg(args, int), count);
	if (*specifier == 's')
		ftprint_str(va_arg(args, char *), count);
	if (*specifier == 'd' || *specifier == 'i')
		ftprint_nbr((long)(va_arg(args, int)), 10, count, "0123456789");
	if (*specifier == 'x')
		ftprint_nbr((long)(va_arg(args, unsigned int)), 16, count,
			"0123456789abcdef");
	if (*specifier == 'X')
		ftprint_nbr((long)(va_arg(args, unsigned int)), 16, count,
			"0123456789ABCDEF");
	if (*specifier == 'p')
		ftprint_adress(va_arg(args, unsigned long), count);
	if (*specifier == 'u')
		ftprint_nbr((long)va_arg(args, unsigned int), 10, count, "0123456789");
	if (*specifier == '%')
		ftprint_char('%', count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			check_format(args, ++format, &count);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
