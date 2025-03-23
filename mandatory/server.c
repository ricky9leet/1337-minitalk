/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltellat <iltellat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:17:14 by iltellat          #+#    #+#             */
/*   Updated: 2025/03/23 12:30:04 by iltellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_ack(siginfo_t *info)
{
	if (kill(info->si_pid, SIGUSR2) == -1)
	{
		ft_printf(RED "Error : Unable to send acknowledgment signal\n" RE);
		exit(EXIT_FAILURE);
	}
}

void	received_bit(int signal, siginfo_t *info, void *context)
{
	static int	bits;
	static char	byte;
	static int	previous_pid;

	(void)context;
	if (previous_pid != info->si_pid)
	{
		previous_pid = info->si_pid;
		bits = 0;
		byte = 0;
	}
	byte = byte << 1 | (signal == SIGUSR2);
	bits++;
	if (bits == 8)
	{
		if (byte == '\0')
			write(1, "\n", 1);
		else
			write(1, &byte, 1);
		bits = 0;
		byte = 0;
	}
	send_ack(info);
}

void	ft_init(void)
{
	struct sigaction	sig;

	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = received_bit;
	if (sigaction(SIGUSR1, &sig, NULL) == -1
		|| sigaction(SIGUSR2, &sig, NULL) == -1)
		exit(1);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf(MAGENTA "Server PID: %d\n" RE, pid);
	ft_printf(YELLOW "waiting for message...\n" RE);
	ft_init();
	while (1)
		pause();
	return (0);
}
