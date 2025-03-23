/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iltellat <iltellat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:57:52 by iltellat          #+#    #+#             */
/*   Updated: 2024/11/13 19:39:40 by iltellat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_putnbr_base(size_t nbr, char *base)
{
	size_t	size;
	int		count;

	count = 0;
	size = ft_strlen(base);
	if (nbr >= size)
	{
		count += ft_putnbr_base(nbr / size, base);
	}
	count += ft_putchar(base[nbr % size]);
	return (count);
}
