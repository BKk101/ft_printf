/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writef_scelse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:58:32 by bykim             #+#    #+#             */
/*   Updated: 2020/05/15 16:52:09 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

int	write_fs(va_list ap, t_format f_info)
{
	char	*temp;
	char	*str1;
	char	*str2;
	int		size;

	f_info.type = 's';
	temp = va_arg(ap, char *);
	str1 = apply_precision_str(temp, f_info);
	size = (f_info.width > ft_strlen(str1) ? f_info.width : ft_strlen(str1));
	str2 = apply_minus_zero_width(size, str1, f_info);
	write(1, str2, size);
	free(str2);
	return (size);
}

int	write_fc(va_list ap, t_format f_info)
{
	char	temp;
	char	*str1;
	char	*str2;
	int		size;

	f_info.type = 'c';
	temp = va_arg(ap, int);
	str1 = (char *)malloc(2);
	str1[0] = temp;
	str1[1] = '\0';
	size = (f_info.width > 1 ? f_info.width : 1);
	str2 = apply_minus_zero_width(size, str1, f_info);
	write(1, str2, size);
	free(str2);
	return (size);
}

int	write_felse(char c, t_format f_info)
{
	char	*str1;
	char	*str2;
	int		size;

	f_info.type = 'e';
	str1 = (char *)malloc(2);
	str1[0] = c;
	str1[1] = '\0';
	size = (f_info.width > 1 ? f_info.width : 1);
	str2 = apply_minus_zero_width(size, str1, f_info);
	write(1, str2, size);
	free(str2);
	return (size);
}
