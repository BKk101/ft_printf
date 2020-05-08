/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writef_diu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:58:27 by bykim             #+#    #+#             */
/*   Updated: 2020/05/08 17:01:16 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int write_fdi(va_list ap, t_format f_info)
{
	char    *str1;
	char    *str2;
	int     num;
	int     size;
	
	num = va_arg(ap, int);
	str1 = apply_precision_num(ftt_itoa(num), f_info); 
	str2 = apply_plus_space_negative(num, str1, f_info);
	size = (f_info.width > ft_strlen(str2) ? f_info.width : ft_strlen(str2));
	str1 = apply_minus_zero_width('d', size, str2, f_info);
	write(1, str1, size);
	free(str1);
	return (size);
}

int write_fu(va_list ap, t_format f_info)
{
	char            *str1;
	char            *str2;
	unsigned int    num;
	int             size;
	
	num = va_arg(ap, int);
	str1 = apply_precision_num(ftt_uitoa(num), f_info);
	size = (f_info.width > ft_strlen(str1) ? f_info.width : ft_strlen(str1));
	str2 = apply_minus_zero_width('u', size, str1, f_info);
	write(1, str2, size);
	free(str2);
	return (size);
}