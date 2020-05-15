/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:11:44 by bykim             #+#    #+#             */
/*   Updated: 2020/05/15 17:02:10 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftprintf.h"

static char		*ftt_strcat(t_format f_info, char *dest, char const *src)
{
	if (f_info.type == 'c' && *src == '\0')
		*dest++ = '\0';
	else
	{
		while (*src != '\0')
			*dest++ = *src++;
	}
	return (dest);
}

char			*ft_strjoin(t_format f_info, char const *s1, char const *s2)
{
	char	*temp;
	char	*res;
	int		len;

	len = (f_info.type == 'c' && *s1 == '\0') ? 1 : ft_strlen(s1);
	len += ft_strlen(s2);
	if ((res = (char *)malloc(len + 1)) == 0)
		return (0);
	temp = ftt_strcat(f_info, res, s1);
	temp = ftt_strcat(f_info, temp, s2);
	*temp = 0;
	return (res);
}
