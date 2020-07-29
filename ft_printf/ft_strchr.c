/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/28 10:46:58 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 11:18:34 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int ch)
{
	while (*str != (char)ch && *str)
		str++;
	if (*str == (char)ch)
		return ((char *)str);
	return (NULL);
}
