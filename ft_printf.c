/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 21:25:44 by bykim             #+#    #+#             */
/*   Updated: 2020/05/15 17:14:52 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static void	init_info(t_format *f_info)
{
	f_info->minus = 0;
	f_info->plus = 0;
	f_info->space = 0;
	f_info->hash = 0;
	f_info->zero = 0;
	f_info->width = 0;
	f_info->precision = -1;
	f_info->length = -1;
	f_info->printlen = 0;
	f_info->type = 0;
	f_info->address = 0;
}

int			ft_printf(const char *format, ...)
{
	t_format	f_info;
	va_list		ap;
	int			len;

	va_start(ap, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			init_info(&f_info);
			f_info = check_format(++format, ap, f_info);
			format = f_info.address;
			if (f_info.printlen == -1)
				continue;
			len += f_info.printlen;
		}
		else
		{
			write(1, format++, 1);
			len++;
		}
	}
	va_end(ap);
	return (len);
}
