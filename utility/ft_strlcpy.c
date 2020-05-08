/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 15:12:16 by bykim             #+#    #+#             */
/*   Updated: 2020/05/08 17:26:48 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t len;

	len = 0;
	while (src[len])
		len++;
	while (size > 1 && *src)
	{
		*dest++ = *src++;
		size--;
	}
	if (size != 0)
		*dest = '\0';
	return (len);
}
