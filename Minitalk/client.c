/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:26:56 by bbrahim           #+#    #+#             */
/*   Updated: 2022/02/13 19:45:13 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include<signal.h>
#include<sys/types.h>

void	ft_client_errors(char *s)
{
	ft_putstr_fd(s, 1);
	exit (0);
}

void	ft_send_char_to_server(unsigned char c, int spid)
{
	unsigned char	bit;

	bit = 0b10000000;
	while (bit)
	{
		if (bit & c)
		{
			if (kill(spid, SIGUSR1) == -1)
				ft_client_errors("SIGUSR1 NOT SEND\n");
		}
		else
		{
			if (kill(spid, SIGUSR2) == -1)
				ft_client_errors("SIGUSR2 NOT SEND\n");
		}
		bit >>= 1;
		usleep (300);
	}
}

int	main(int ac, char **av)
{
	int	spid;
	int	i;

	if (ac == 3)
	{
		spid = ft_atoi(av[1]);
		if (spid <= 0)
			ft_client_errors("INVALID SERVER PID\n");
		i = -1;
		while (av[2][++i])
			ft_send_char_to_server(av[2][i], spid);
	}
	else
		ft_client_errors("INVALID NUMBER OF ARGUMENTS\n");
	return (0);
}
