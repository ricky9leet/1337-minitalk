/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltellat <iltellat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:42:05 by iltellat          #+#    #+#             */
/*   Updated: 2025/03/23 12:28:53 by iltellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_ack;

void	confirm_reception(int signum)
{
	(void)signum;
	g_ack = 1;
}

int	get_pid(char *str)
{
	int		i;
	long	pid;

	i = 0;
	while (is_whitespace(str[i]))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (is_whitespace(str[i]))
		i++;
	if (str[i])
	{
		ft_printf(RED "Error : Invalid PID\n" RE);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(str);
	return (pid);
}

void	init_signal_handler(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_handler = &confirm_reception;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf(RED "Error: sigaction failed.\n" RE);
		exit(EXIT_FAILURE);
	}
}

void	send_char(int pid, char c)
{
	int	i;
	int	timeout;

	i = 7;
	while (i >= 0)
	{
		g_ack = 0;
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		timeout = 0;
		while (!g_ack && timeout < 500)
		{
			usleep(100);
			timeout++;
		}
		if (timeout >= 500)
		{
			ft_printf(RED "Error: Server not responding\n" RE);
			exit(EXIT_FAILURE);
		}
		usleep(50);
		i--;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*msg;

	if (ac != 3)
	{
		ft_printf(YELLOW "Usage: ./client [PID] [Message]\n" RE);
		return (1);
	}
	pid = get_pid(av[1]);
	if (pid == -1337 || kill(pid, 0) == -1)
	{
		ft_printf(RED "Error: Invalid PID\n" RE);
		exit(EXIT_FAILURE);
	}
	init_signal_handler();
	msg = av[2];
	while (*msg)
		send_char(pid, *msg++);
	send_char(pid, '\0');
	return (0);
}
