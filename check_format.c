/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:54:51 by bykim             #+#    #+#             */
/*   Updated: 2020/05/15 17:42:57 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char g_f_syn[] = "-+ 0#.*123456789hl";

static void	get_width(const char **arg, t_format *f_info)
{
	f_info->width = ft_atoi(*arg);
	*arg += ft_numlen(f_info->width);
}

static void	get_asterisk(const char **arg, t_format *f_info, char c, va_list ap)
{
	int asterisk;

	asterisk = va_arg(ap, int);
	if (c == 'w')
	{
		if (asterisk < 0)
		{
			f_info->minus = 1;
			f_info->width = -1 * asterisk;
		}
		else
			f_info->width = asterisk;
	}
	else if (c == 'p')
	{
		if (asterisk < 0)
			f_info->precision = -1;
		else
			f_info->precision = asterisk;
	}
	*arg += 1;
}

static void	get_precision(const char **arg, t_format *f_info, va_list ap)
{
	(*arg)++;
	if (**arg == '*')
		get_asterisk(arg, f_info, 'p', ap);
	else
	{
		f_info->precision = ft_atoi(*arg);
		while (**arg >= '0' && **arg <= '9')
			*arg = *arg + 1;
	}
}

static void	get_else(const char **arg, t_format *f_info)
{
	if (**arg == '-')
		f_info->minus = 1;
	else if (**arg == '+')
		f_info->plus = 1;
	else if (**arg == ' ')
		f_info->space = 1;
	else if (**arg == '0')
		f_info->zero = 1;
	*arg += 1;
}

t_format	check_format(const char *arg, va_list ap, t_format f_info)
{
	while (ft_ischarset(*arg, g_f_syn))
	{
		if (*arg >= '1' && *arg <= '9')
			get_width(&arg, &f_info);
		else if (*arg == '.')
			get_precision(&arg, &f_info, ap);
		else if (*arg == '*')
			get_asterisk(&arg, &f_info, 'w', ap);
		else
			get_else(&arg, &f_info);
	}
	if ((f_info.printlen = classify_type(*arg, ap, f_info)) == -1)
		f_info.address = arg;
	else
		f_info.address = arg + 1;
	return (f_info);
}
