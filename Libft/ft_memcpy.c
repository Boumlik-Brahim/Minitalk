/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:48:33 by bbrahim           #+#    #+#             */
/*   Updated: 2021/11/22 12:14:40 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void*dst, const	void*src, size_t n)
{
	unsigned char	*sr;
	unsigned char	*ds;
	size_t			i;

	sr = (unsigned char *)src;
	ds = (unsigned char *)dst;
	if (sr == NULL && ds == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dst);
}
