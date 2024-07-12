/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfreire <alfreire@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:45:28 by alfreire          #+#    #+#             */
/*   Updated: 2024/07/12 22:29:49 by alfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

void	bit2server(int pid, char *str, size_t len)
{
	int		bit_posi;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		bit_posi = 0;
		while (bit_posi < 8)
		{
			if ((str[i] >> bit_posi) & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit_posi++;
			usleep(300);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		bit2server(pid, str, ft_strlen(str));
	}
	else
		ft_printf("You need to use 2 arguments:\n<PID> <STRING>\n");
	return (0);
}
