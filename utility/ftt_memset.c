/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 15:17:03 by bykim             #+#    #+#             */
/*   Updated: 2020/05/08 17:27:10 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ftt_memset(void *s, int c, size_t n)
{
	unsigned char	*temp;
	unsigned long	idx;

	temp = (unsigned char *)s;
	idx = 0;
	while (idx < n - 1)
		temp[idx++] = (unsigned char)c;
	temp[idx] = '\0';
	return (s);
}
