/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:45:40 by alfreire          #+#    #+#             */
/*   Updated: 2024/07/12 21:58:42 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include "libft/libft.h"

void	print_bit(int signal)
{
	static int	bit_posi;
	static int	i;

	if (signal == SIGUSR2)
		i |= (0x01 << bit_posi);
	bit_posi++;
	if (bit_posi == 8)
	{
		ft_printf("%c", i);
		if (!i)
			ft_printf("\n");
		bit_posi = 0;
		i = 0;
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, print_bit);
		signal(SIGUSR2, print_bit);
		pause();
	}
	return (0);
}
