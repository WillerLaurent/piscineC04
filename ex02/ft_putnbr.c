/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 14:21:59 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/22 14:32:42 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_char(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_write_char('-');
		nb = nb * (-1);
		if (nb == -2147483648)
		{
			ft_write_char('2');
			nb = 147483648;
		}
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_write_char(nb % 10 + '0');
}
