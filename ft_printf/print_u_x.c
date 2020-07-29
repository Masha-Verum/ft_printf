/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:34:47 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 12:21:00 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	prn_u_x(unsigned long long int value, int base, t_tmpl *tmpl)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (tmpl->precision > -1)
		tmpl->zero = 0;
	if (tmpl->type == 'p')
		j = 2;
	while (value != 0 || (i == 0 && tmpl->precision != 0))
	{
		value = value / base;
		i++;
	}
	if (tmpl->precision > i)
		tmpl->precision -= i;
	else
		tmpl->precision = 0;
	tmpl->str_length = j + i + tmpl->precision;
	if (tmpl->width > tmpl->str_length && tmpl->zero == 1)
		tmpl->str_length = tmpl->width;
	if (!(tmpl->str = malloc(sizeof(int) * (tmpl->str_length + 1))))
		tmpl->error = 1;
	return (tmpl->error);
}

void		get_u_x(unsigned long long int value, int base, t_tmpl *tmpl, \
																	char *s)
{
	int	i;

	if (prn_u_x(value, base, tmpl) == 0)
	{
		tmpl->str[tmpl->str_length] = '\0';
		i = tmpl->str_length - 1;
		if (value == 0 && tmpl->precision != 0)
			tmpl->str[i--] = '0';
		while (value != 0)
		{
			tmpl->str[i--] = s[value % base];
			value /= base;
		}
		while (i >= 0)
			tmpl->str[i--] = '0';
		if (tmpl->type == 'p')
		{
			tmpl->str[0] = '0';
			tmpl->str[1] = 'x';
		}
	}
}

void		print_u(t_tmpl *template, int base, char *symbols)
{
	unsigned long long int value;

	value = va_arg(template->args, unsigned int);
	get_u_x(value, base, template, symbols);
}
