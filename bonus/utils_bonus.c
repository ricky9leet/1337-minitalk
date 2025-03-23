/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltellat <iltellat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 22:53:22 by iltellat          #+#    #+#             */
/*   Updated: 2025/03/23 12:27:34 by iltellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	send_ack(siginfo_t *info, int signal)
{
	if (kill(info->si_pid, signal) == -1)
	{
		ft_printf(RED "Error : Unable to send acknowledgment signal\n" RE);
	}
}

long	ft_atoi(char *str)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
		sign = 44 - *str++;
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	return (res * sign);
}

int	ft_equals(const char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

void	terminate(siginfo_t *info, int *bits, unsigned char *byte, int *pos)
{
	write(1, "\n", 1);
	send_ack(info, SIGUSR1);
	reset_state(bits, byte, pos);
}

void	reset_state(int *bits, unsigned char *byte, int *pos)
{
	*bits = 0;
	*byte = 0;
	*pos = 0;
}
