/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_multifree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bykim <bykim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:30:37 by bykim             #+#    #+#             */
/*   Updated: 2020/05/11 23:39:12 by bykim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdarg.h>

void	ft_multifree(int args, ...)
{
	va_list	ap;
	char	*ptr;
	int		i;

	va_start(ap, args);
	i = 0;
	while (i++ < args)
	{
		ptr = va_arg(ap, char *);
		free(ptr);
	}
	va_end(ap);
}
