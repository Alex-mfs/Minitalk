/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_adress.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:26:50 by alfreire          #+#    #+#             */
/*   Updated: 2024/07/12 13:18:02 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	get_adress(unsigned long n, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (n >= 16)
		get_adress(n / 16, count);
	*count += write(1, &hexa[n % 16], 1);
}

void	ftprint_adress(unsigned long nbr, int *count)
{
	if (!nbr)
	{
		*count += write(1, "(nil)", 5);
		return ;
	}
	*count += write(1, "0x", 2);
	get_adress(nbr, count);
}

/*
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	a = 42;
	int	count = 0;

	ftprint_adress((unsigned long)&a, &count);
	write(1, "\n", 1);
	printf("%p", &a);
	return 0;
}
*/