/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 09:53:13 by bbrahim           #+#    #+#             */
/*   Updated: 2022/02/13 23:02:54 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include<signal.h>
#include<sys/types.h>

static char	g_last_char;

void	ft_server_errors(char *s)
{
	ft_putstr_fd(s, 1);
	exit (0);
}

void	ft_reset_count(int *i, char *c)
{
	*i = 0;
	*c = 0;
}

void	ft_sig_handler(int signum, siginfo_t *siginfo, void *ucontext)
{
	static int	p;
	static char	unic;
	static int	cpid;
	static int	ocpid;

	(void)ucontext;
	
	cpid = siginfo->si_pid;
	if (cpid != ocpid && cpid != 0)
	{
		if ((last_char >> 8 & 1))
			ft_putchar_fd(8, 1);
		ft_reset_count(&p, &unic);
		ocpid = cpid;
	}
	if (signum == SIGUSR1)
		unic += (128 >> p);
	p++;
	if (p == 8)
	{
		if (unic == 0)
			kill(siginfo->si_pid, SIGUSR2);
		ft_putchar_fd(unic, 1);
		g_last_char = unic;
		ft_reset_count(&p, &unic);
	}
}

int	main(void)
{
	struct sigaction	sas;
	int					pid;

	sas.sa_flags = SA_SIGINFO;
	sas.sa_sigaction = ft_sig_handler;
	pid = getpid();
	ft_putstr_fd("SERVER PID => ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	sigaction(SIGUSR1, &sas, NULL);
	sigaction(SIGUSR2, &sas, NULL);
	while (1)
		pause();
	return (0);
}
