/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:50:52 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/22 14:59:19 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write_char(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_test_base(char *base)
{
	int i;
	int j;
	int ln_base;

	i = 0;
	j = 1;
	ln_base = ft_strlen(base);
	if (ln_base < 2)
		return (0);
	while (i < ln_base - 1)
	{
		while (j < ln_base)
		{
			if (base[i] == base[j])
				return (0);
			if (base[i] == '-' || base[i] == '-' || base[j] == '+' ||
					base[j] == '+')
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	bs;
	unsigned int	a;

	if (!ft_test_base(base))
		return ;
	bs = ft_strlen(base);
	if (nbr >= 0)
		a = nbr;
	if (nbr < 0)
	{
		a = nbr * (-1);
		ft_write_char('-');
	}
	if (a > bs - 1)
	{
		ft_putnbr_base(a / bs, base);
	}
	ft_write_char(base[a % bs]);
}
