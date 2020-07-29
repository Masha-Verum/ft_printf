/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 19:33:11 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 11:56:28 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_s(char *string, t_tmpl *template)
{
	if (string == NULL)
	{
		template->str_length = 6;
		string = "(null)";
	}
	else
		template->str_length = ft_strlen(string);
	if (template->precision != -1 && template->precision < template->str_length)
		template->str_length = template->precision;
	if (!(template->str = malloc(sizeof(char) * (template->str_length + 1))))
		template->error = 1;
	else
		ft_memcpy(template->str, string, template->str_length);
}

void	print_c(int symbol, t_tmpl *template)
{
	template->str = malloc(2 * sizeof(char));
	if (template->str == NULL)
		template->error = 1;
	else
	{
		template->str[0] = symbol;
		template->str[1] = '\0';
		template->str_length = 1;
	}
}
