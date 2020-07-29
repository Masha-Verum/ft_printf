/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 12:25:11 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/28 10:46:08 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_memory(int num, int i)
{
	char	*str;

	if (num < 0)
	{
		str = (char *)ft_calloc(i + 2, 1);
		if (NULL == str)
			return (NULL);
		str[0] = '-';
	}
	else
	{
		str = (char *)ft_calloc(i + 1, 1);
		if (NULL == str)
			return (NULL);
	}
	return (str);
}

static char		*ft_zero(int n)
{
	char		*str;
	long		i;

	i = 1;
	str = ft_memory(n, i);
	if (NULL == str)
		return (NULL);
	*str = '0';
	return (str);
}

static int		ft_non_zero(long n, long i)
{
	long		num;

	num = n;
	while (num >= 10)
	{
		i++;
		num /= 10;
	}
	return (i);
}

static char		*ft_str_fill(char *str, long num, int n, long i)
{
	while (i)
	{
		num = n % 10;
		n = n / 10;
		if (n >= 0 && num >= 0)
			str[i - 1] = num + 48;
		else if (n <= 0 && num <= 0)
			str[i] = num * -1 + 48;
		i--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	long		num;
	long		i;
	char		*str;

	num = n;
	i = 1;
	if (n == 0)
	{
		str = ft_zero(n);
		return (str);
	}
	if (num < 0)
		num = num * -1;
	i = ft_non_zero(num, i);
	str = ft_memory(n, i);
	if (NULL == str)
		return (NULL);
	num = n;
	str = ft_str_fill(str, num, n, i);
	return (str);
}
