/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltellat <iltellat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:42:05 by iltellat          #+#    #+#             */
/*   Updated: 2025/03/23 12:29:25 by iltellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_ack;

void	confirm_reception(int signum)
{
	if (signum == SIGUSR2)
		g_ack = 1;
	else if (signum == SIGUSR1)
	{
		ft_printf(GREEN "Message recieved!!\n" RE);
		exit(EXIT_SUCCESS);
	}
}

int	get_pid(char *str)
{
	int		i;
	long	pid;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9')
			|| ft_equals(str[i]))
			return (-1337);
		i++;
	}
	pid = ft_atoi(str);
	if (pid > INT_MAX || pid <= 0)
		return (-1337);
	return (pid);
}

void	init_signal_handler(void)
{
	struct sigaction	sa;

	sa.sa_handler = &confirm_reception;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
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
		while (!g_ack && timeout < 5000)
		{
			usleep(200);
			timeout++;
		}
		if (timeout >= 5000)
		{
			ft_printf(RED "Error: Server not responding\n" RE);
			exit(EXIT_FAILURE);
		}
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
