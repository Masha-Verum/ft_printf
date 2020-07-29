/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:34:34 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 11:49:32 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_precision(const char *s, int i, t_tmpl *template)
{
	template->precision = 0;
	if (s[i] == '*')
	{
		template->precision = va_arg(template->args, int);
		i++;
	}
	else
	{
		while (ft_strchr("0123456789", s[i]) != 0)
		{
			template->precision = template->precision * 10 + (s[i] - '0');
			i++;
		}
	}
	if (template->precision < 0)
		template->precision = -1;
	return (i);
}

static int	find_width(const char *s, int i, t_tmpl *template)
{
	if (s[i] == '*')
	{
		i++;
		template->width = va_arg(template->args, int);
		if (template->width < 0)
		{
			template->minus = 1;
			template->width = -template->width;
			template->zero = 0;
		}
	}
	else
	{
		while (ft_strchr("0123456789", s[i]) != 0)
		{
			template->width = template->width * 10 + (s[i] - '0');
			i++;
		}
	}
	return (i);
}

static int	find_flag(const char *s, int i, t_tmpl *template)
{
	i = template->index;
	while (ft_strchr("-0", s[i]) != 0)
	{
		if (s[i] == '0')
			template->zero = 1;
		if (s[i] == '-')
		{
			template->minus = 1;
			template->zero = 0;
		}
		i++;
	}
	return (i);
}

int			parse_format(const char *s, t_tmpl *template)
{
	int i;

	i = 0;
	i = find_flag(s, i, template);
	i = find_width(s, i, template);
	if (s[i] == '.')
	{
		i++;
		i = find_precision(s, i, template);
	}
	if (ft_strchr("cspdiuxX%", s[i]) != 0)
	{
		template->type = s[i];
		if (print_type(template) == -1)
			return (-1);
		template->index = i + 1;
	}
	else
	{
		write(1, "%", 1);
		template->qty++;
	}
	return (0);
}
