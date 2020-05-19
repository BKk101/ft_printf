/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:14:06 by bykim             #+#    #+#             */
/*   Updated: 2020/05/15 16:55:49 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

char	*apply_precision_num(char *str, t_format f_info)
{
	char	*temp;
	char	*res;
	int		len;

	len = ft_strlen(str);
	temp = (char *)malloc(f_info.precision - len + 1);
	if (*str == '0' && f_info.precision == 0)
		str[0] = '\0';
	if (f_info.precision > len)
	{
		ftt_memset(temp, '0', f_info.precision - len + 1);
		res = ft_strjoin(f_info, temp, str);
	}
	else
		res = ft_strjoin(f_info, str, "");
	ft_multifree(2, str, temp);
	return (res);
}

char	*apply_precision_str(char *str, t_format f_info)
{
	char	*res;
	int		len;

	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (f_info.precision >= 0 && f_info.precision < len)
	{
		res = (char *)malloc(f_info.precision + 1);
		ft_strlcpy(res, str, f_info.precision + 1);
	}
	else
	{
		res = (char *)malloc(len + 1);
		ft_strlcpy(res, str, len + 1);
	}
	return (res);
}

char	*apply_plus_space_negative(long long num, char *str, t_format f_info)
{
	char	*res;

	if (num < 0)
		res = ft_strjoin(f_info, "-", str);
	else if (num >= 0 && f_info.plus > 0)
		res = ft_strjoin(f_info, "+", str);
	else if (num >= 0 && f_info.space > 0)
		res = ft_strjoin(f_info, " ", str);
	else
		res = ft_strjoin(f_info, str, "");
	free(str);
	return (res);
}

char	*apply_minus_zero_width(int size, char *str, t_format f_info)
{
	char	*temp;
	char	*res;
	int		len;
	int		flag;

	len = (f_info.type == 'c') ? 1 : ft_strlen(str);
	temp = (char *)malloc(size - len + 1);
	if (f_info.minus > 0 && f_info.width > len)
	{
		ftt_memset(temp, ' ', size - len + 1);
		res = ft_strjoin(f_info, str, temp);
	}
	else if (f_info.width > len)
	{
		if (f_info.precision >= 0 && !(f_info.type == 's' ||
		f_info.type == 'e'))
			f_info.zero = 0;
		flag = (f_info.zero > 0 ? '0' : ' ');
		ftt_memset(temp, flag, size - len + 1);
		res = ft_strjoin(f_info, temp, str);
	}
	else
		res = ft_strjoin(f_info, str, "");
	ft_multifree(2, str, temp);
	return (res);
}
