/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltellat <iltellat@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 01:15:09 by iltellat          #+#    #+#             */
/*   Updated: 2025/03/23 12:25:08 by iltellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../ft_printf/ft_printf.h"

long	ft_atoi(char *str);

void	terminate(siginfo_t *info, int *bits, unsigned char *byte, int *pos);
void	reset_state(int *bits, unsigned char *byte, int *pos);
void	send_ack(siginfo_t *info, int signal);
int		ft_equals(char c);

// ansi code colors
# define RE "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

#endif