/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_unsig.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:34:17 by alfreire          #+#    #+#             */
/*   Updated: 2024/07/12 13:20:29 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <unistd.h>
// #include <stdio.h>

void	ftprint_unsig(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ftprint_unsig(n / 10, count);
		n = n % 10;
	}
	if (n < 10)
	{
		n += 48;
		*count += write(1, &n, 1);
	}
}
