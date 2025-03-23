/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltellat <iltellat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:17:14 by iltellat          #+#    #+#             */
/*   Updated: 2025/03/23 12:27:02 by iltellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	process_byte(unsigned char *buffer, int *pos, unsigned char *byte)
{
	unsigned char	lead;
	int				len;

	buffer[(*pos)++] = *byte;
	if (*pos == 1 && (*byte & 0x80) == 0)
	{
		write(1, buffer, 1);
		*pos = 0;
		return ;
	}
	lead = buffer[0];
	len = 0;
	if ((lead & 0b11100000) == 0b11000000)
		len = 2;
	else if ((lead & 0b11110000) == 0b11100000)
		len = 3;
	else if ((lead & 0b11111000) == 0b11110000)
		len = 4;
	if (len > 0 && *pos == len)
	{
		write(1, buffer, len);
		*pos = 0;
	}
}

void	received_bit(int signal, siginfo_t *info, void *context)
{
	static int				bits;
	static unsigned char	byte;
	static int				previous_pid;
	static unsigned char	buffer[4];
	static int				buffer_pos;

	(void)context;
	if (previous_pid != info->si_pid)
	{
		previous_pid = info->si_pid;
		reset_state(&bits, &byte, &buffer_pos);
	}
	byte = (byte << 1) | (signal == SIGUSR2);
	if (++bits == 8)
	{
		if (byte == '\0')
			terminate(info, &bits, &byte, &buffer_pos);
		process_byte(buffer, &buffer_pos, &byte);
		bits = 0;
		byte = 0;
	}
	send_ack(info, SIGUSR2);
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
