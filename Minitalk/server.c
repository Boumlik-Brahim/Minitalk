/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 15:27:18 by bbrahim           #+#    #+#             */
/*   Updated: 2022/02/13 19:53:28 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../Libft/libft.h"
#include<signal.h>
#include<sys/types.h>

void	sig_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	static int		p;
	static int		ascii;
	static int		cpid;
	static int		ocpid;
	unsigned char	bit;

	(void)ucontext;
	bit = 0b10000000;
	cpid = siginfo->si_pid;
	if (cpid != ocpid && cpid != 0)
	{
		ocpid = cpid;
		p = 0;
		ascii = 0;
	}
	if (signum == SIGUSR1)
		ascii += (bit >> p);
	p++;
	if (p == 8)
	{
		ft_putchar_fd(ascii, 1);
		p = 0;
		ascii = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_handler;
	pid = getpid();
	ft_putstr_fd("SERVER PID => ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
