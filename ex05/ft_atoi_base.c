/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwiller <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 11:17:34 by lwiller           #+#    #+#             */
/*   Updated: 2020/09/22 15:04:07 by lwiller          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_test_whitespace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r' ||
			c == ' ' || c == '-' || c == '+')
		return (0);
	return (1);
}

int		ft_test_base(char *base)
{
	int i;
	int j;
	int ln_base;

	i = 0;
	j = i + 1;
	ln_base = ft_strlen(base);
	if (ln_base < 2)
		return (0);
	while (i < ln_base - 1)
	{
		while (j < ln_base)
		{
			if (base[i] == base[j])
				return (0);
			if (!ft_test_whitespace(base[i]))
				return (0);
			if (!ft_test_whitespace(base[j]))
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

int		ft_convert(char *str, int i, char *base)
{
	int j;
	int rtn;
	int ln_bs;

	rtn = 0;
	ln_bs = ft_strlen(base);
	while (str[i])
	{
		j = 0;
		while ((str[i] != base[j]))
		{
			j++;
			if (j > ln_bs)
				return (rtn);
		}
		rtn = (rtn * ln_bs) + j;
		i++;
	}
	return (rtn);
}

int		ft_atoi_base(char *str, char *base)
{
	int sign;
	int i;
	int rtn;

	i = 0;
	sign = 1;
	if (!ft_test_base(base))
		return (0);
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}
	rtn = ft_convert(str, i, base);
	return (rtn * sign);
}
