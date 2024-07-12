/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprint_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:46:37 by alfreire          #+#    #+#             */
/*   Updated: 2024/07/12 13:18:47 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ftprint_nbr(long nbr, int base, int *count, char *symbols)
{
	if (nbr < 0)
	{
		ftprint_char('-', count);
		nbr = -nbr;
	}
	if (nbr >= base)
		ftprint_nbr(nbr / base, base, count, symbols);
	ftprint_char(symbols[nbr % base], count);
}
