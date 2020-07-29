/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:34:53 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 11:56:28 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_width(t_tmpl *template, char symbol)
{
	int i;

	i = template->width - template->str_length;
	if (i > 0 && template->minus == 0)
	{
		if (template->type == '%' && template->zero == 1)
			symbol = '0';
		while (i > 0)
		{
			write(1, &symbol, 1);
			template->qty++;
			i--;
		}
	}
	ft_putstr(template);
	free(template->str);
	if (i > 0 && template->minus == 1)
	{
		while (i > 0)
		{
			write(1, &symbol, 1);
			template->qty++;
			i--;
		}
	}
}
