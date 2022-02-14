/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:16:09 by bbrahim           #+#    #+#             */
/*   Updated: 2021/11/21 10:44:40 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char*dst, const char*src, size_t dstsize)
{
	size_t	i;
	size_t	sl;
	size_t	dl;

	sl = ft_strlen(src);
	dl = ft_strlen(dst);
	if (dstsize < dl)
		return (dstsize + sl);
	i = 0;
	while (i + 1 + dl < dstsize && src[i] != '\0')
	{
		dst[dl + i] = src[i];
		i++;
	}
	dst[dl + i] = '\0';
	return (dl + sl);
}
