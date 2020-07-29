/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:34:50 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 12:24:04 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	value_negative(t_tmpl *tmpl, int value)
{
	if (value < 0)
	{
		tmpl->precision = tmpl->precision - tmpl->str_length + 1;
		tmpl->str_length = tmpl->str_length + tmpl->precision;
	}
	else
	{
		tmpl->precision = tmpl->precision - tmpl->str_length;
		tmpl->str_length = tmpl->str_length + tmpl->precision;
	}
}

static int	d_precision(int value, t_tmpl *tmpl)
{
	char *str_num;

	str_num = ft_itoa(value);
	tmpl->str_length = ft_strlen(str_num);
	free(str_num);
	if (tmpl->precision > -1)
		tmpl->zero = 0;
	if (tmpl->precision == 0 && value == 0)
		tmpl->str_length = 0;
	if (tmpl->precision >= (tmpl->str_length))
	{
		value_negative(tmpl, value);
	}
	if (tmpl->width > tmpl->str_length && tmpl->zero == 1)
		tmpl->str_length = tmpl->width;
	if (!(tmpl->str = malloc(sizeof(int) * (tmpl->str_length + 1))))
		tmpl->error = 1;
	return (tmpl->error);
}

static void	get_d(int long value, t_tmpl *tmpl)
{
	int	long	new_value;
	int			i;

	if (d_precision(value, tmpl) == 0)
	{
		tmpl->str[tmpl->str_length] = '\0';
		i = tmpl->str_length - 1;
		if (value >= 0)
			new_value = value;
		else
			new_value = value * -1;
		while (new_value != 0)
		{
			tmpl->str[i--] = new_value % 10 + '0';
			new_value /= 10;
		}
		if (value == 0 && tmpl->precision != 0)
			tmpl->str[i--] = '0';
		while (i >= 0)
			tmpl->str[i--] = '0';
		if (value < 0)
			tmpl->str[0] = '-';
	}
}

void		print_d(t_tmpl *tmpl)
{
	int long long value;

	value = va_arg(tmpl->args, int);
	get_d(value, tmpl);
}
