/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 21:11:44 by bykim             #+#    #+#             */
/*   Updated: 2020/05/08 17:40:40 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlen(const char *s)
{
	int len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static char		*ftt_strcat(char *dest, char const *src)
{
	while (*src != '\0')
		*dest++ = *src++;
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	char	*res;
	int		len;

	len = ft_strlen(s1);
	len += ft_strlen(s2);
	if ((res = (char *)malloc(len + 1)) == 0)
	{
		return (0);
	}
	temp = ftt_strcat(res, s1);
	temp = ftt_strcat(temp, s2);
	*temp = 0;
	return (res);
}
