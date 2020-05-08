/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classify_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 14:49:13 by bykim             #+#    #+#             */
/*   Updated: 2020/05/08 17:45:17 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	classify_type(char c, va_list ap, t_format f_info)
{
	if (c == '\0')
		return (-1);
	else if (c == 'c')
		return (write_fc(ap, f_info));
	else if (c == 's')
		return (write_fs(ap, f_info));
	else if (c == 'p')
		return (write_fp(ap, f_info));
	else if (c == 'd' || c == 'i')
		return (write_fdi(ap, f_info));
	else if (c == 'u')
		return (write_fu(ap, f_info));
	else if (c == 'x' || c == 'X')
		return (write_fxx(ap, f_info, c));
	else
		return (write_felse(c, f_info));
}
