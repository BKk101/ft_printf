/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftt_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 15:03:41 by bykim             #+#    #+#             */
/*   Updated: 2020/05/08 17:29:52 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ftt_itoa(int n)
{
	long long	temp;
	size_t		len;
	char		*res;

	len = 1;
	temp = n;
	if (n < 0)
		temp *= -1;
	while ((temp /= 10) > 0)
		len++;
	if ((res = (char *)malloc(len + 1)) == 0)
		return (0);
	if (n == 0)
		res[0] = '0';
	temp = (long long)n * 10;
	if (n < 0)
		temp *= -1;
	res[len] = '\0';
	while ((temp /= 10) > 0)
		res[--len] = temp % 10 + '0';
	return (res);
}

char		*ftt_uitoa(unsigned int n)
{
	long long	temp;
	size_t		len;
	char		*res;

	len = 1;
	temp = n;
	while ((temp /= 10) > 0)
		len++;
	if ((res = (char *)malloc(len + 1)) == 0)
		return (0);
	if (n == 0)
		res[0] = '0';
	temp = (long long)n * 10;
	res[len] = '\0';
	while ((temp /= 10) > 0)
		res[--len] = temp % 10 + '0';
	return (res);
}
