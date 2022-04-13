/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbascuna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:19:52 by mbascuna          #+#    #+#             */
/*   Updated: 2021/11/24 17:02:17 by mbascuna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst2;
	char		*src2;

	dst2 = (char *)dst;
	src2 = (char *)src;
	i = 0;
	if (dst2 > src2)
	{
		while (len > 0)
		{
			len--;
			dst2[len] = src2[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
