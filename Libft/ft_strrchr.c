/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 15:41:27 by bbrahim           #+#    #+#             */
/*   Updated: 2021/11/21 11:00:18 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const	char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len > 0 && s[len] != c)
		len--;
	if (s[len] == (char)c)
		return ((char *)(s + len));
	else
		return (NULL);
}
