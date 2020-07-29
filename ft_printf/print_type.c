/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:34:56 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 12:10:54 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				print_type(t_tmpl *template)
{
	if (template->type == '%')
		print_c('%', template);
	if (template->type == 'c')
		print_c(va_arg(template->args, int), template);
	if (template->type == 's')
		print_s(va_arg(template->args, char*), template);
	if (template->type == 'd' || template->type == 'i')
		print_d(template);
	if (template->type == 'u')
		print_u(template, 10, "0123456789");
	if (template->type == 'x')
		print_u(template, 16, "0123456789abcdefx");
	if (template->type == 'X')
		print_u(template, 16, "0123456789ABCDEFX");
	if (template->type == 'p')
		get_u_x(va_arg(template->args, size_t), 16, template, \
											"0123456789abcdefx");
	if (template->error == 1)
		return (-1);
	print_width(template, ' ');
	return (0);
}
