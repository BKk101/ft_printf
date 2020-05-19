/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   writef_pxx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 23:09:10 by bykim             #+#    #+#             */
/*   Updated: 2020/05/15 16:51:23 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char g_hex_lower[] = "0123456789abcdef";
static char g_hex_upper[] = "0123456789ABCDEF";

static char	*convert_hex(long long memory, char c)
{
	long long	temp;
	size_t		len;
	char		*res;

	len = 1;
	temp = memory;
	while ((temp /= 16) > 0)
		len++;
	if ((res = (char *)malloc(len + 1)) == 0)
		return (0);
	if (memory == 0)
		res[0] = '0';
	temp = memory * 16;
	res[len] = '\0';
	while ((temp /= 16) > 0)
	{
		if (c == 'x')
			res[--len] = g_hex_lower[temp % 16];
		else if (c == 'X')
			res[--len] = g_hex_upper[temp % 16];
	}
	return (res);
}

int			write_fp(va_list ap, t_format f_info)
{
	char	*str1;
	char	*str2;
	char	*temp;
	int		size;

	f_info.type = 'p';
	temp = va_arg(ap, char *);
	str1 = apply_precision_num(convert_hex((long long)temp, 'x'), f_info);
	temp = ft_strjoin(f_info, "0x", str1);
	size = (f_info.width > ft_strlen(temp) ? f_info.width : ft_strlen(temp));
	str2 = apply_minus_zero_width(size, temp, f_info);
	write(1, str2, size);
	ft_multifree(2, str1, str2);
	return (size);
}

int			write_fxx(va_list ap, t_format f_info, char c)
{
	char			*str1;
	char			*str2;
	unsigned int	temp;
	int				size;

	f_info.type = 'x';
	temp = va_arg(ap, unsigned int);
	str1 = apply_precision_num(convert_hex(temp, c), f_info);
	size = (f_info.width > ft_strlen(str1) ? f_info.width : ft_strlen(str1));
	str2 = apply_minus_zero_width(size, str1, f_info);
	write(1, str2, size);
	ft_multifree(1, str2);
	return (size);
}
