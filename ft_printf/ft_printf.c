/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:27:06 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 11:56:28 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	new_struct(t_tmpl *template)
{
	template->minus = 0;
	template->zero = 0;
	template->width = 0;
	template->precision = -1;
	template->type = 0;
	template->str = NULL;
	template->str_length = 0;
	template->error = 0;
}

int			ft_printf(const char *format, ...)
{
	t_tmpl	template;

	template.index = 0;
	template.qty = 0;
	va_start(template.args, format);
	if (format == NULL)
		return (-1);
	while (format[template.index] != '\0')
	{
		if (format[template.index] == '%')
		{
			template.index++;
			new_struct(&template);
			if ((parse_format(format, &template) == -1))
				return (-1);
		}
		else
		{
			write(1, &format[template.index], 1);
			template.index++;
			template.qty++;
		}
	}
	va_end(template.args);
	return (template.qty);
}
