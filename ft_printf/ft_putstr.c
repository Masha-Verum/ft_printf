/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 10:56:14 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 11:56:28 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(t_tmpl *template)
{
	if (template->str != NULL)
	{
		template->qty += template->str_length;
		write(1, template->str, template->str_length);
	}
}
