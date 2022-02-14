/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 20:33:40 by bbrahim           #+#    #+#             */
/*   Updated: 2021/11/21 10:09:50 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;
	size_t	len;

	len = count * size;
	str = malloc(len);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, len);
	return (str);
}
