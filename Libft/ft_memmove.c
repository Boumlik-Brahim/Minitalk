/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 18:08:52 by bbrahim           #+#    #+#             */
/*   Updated: 2021/11/22 12:15:34 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	if (n < 0)
		return (NULL);
	if (sr < ds)
	{
		while (n > 0)
		{
			n--;
			ds[n] = sr[n];
		}
		return (ds);
	}
	ds = ft_memcpy(dst, src, n);
	return (ds);
}
