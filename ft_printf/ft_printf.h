/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbantam <mbantam@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 19:27:21 by mbantam           #+#    #+#             */
/*   Updated: 2020/07/29 12:06:27 by mbantam          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef	struct		s_tmpl
{
	va_list			args;
	int				index;
	unsigned int	minus;
	unsigned int	zero;
	int				width;
	int				precision;
	char			type;
	char			*str;
	int				str_length;
	int				qty;
	unsigned int	error;
}					t_tmpl;

void				get_d(int long value, t_tmpl *data);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_itoa(int n);
int					ft_printf(const char *s, ...);
int					parse_format(const char *s, t_tmpl *data);
void				*ftp_memset(void *str, int symbol, size_t n);
void				ft_putstr(t_tmpl *data);
size_t				ft_strlen(const char *s);
char				*ft_strchr(const char *s, int c);
void				print_c(int symnol, t_tmpl *data);
void				print_width(t_tmpl *data, char symbol);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				print_s(char *string, t_tmpl *data);
int					print_type(t_tmpl *template);
void				get_u_x(unsigned long long int val, int base, t_tmpl \
					*data, char *s);
void				print_d(t_tmpl *tmpl);
void				print_u(t_tmpl *template, int base, char *symbols);

#endif
