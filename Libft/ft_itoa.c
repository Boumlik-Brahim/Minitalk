/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 20:24:49 by bbrahim           #+#    #+#             */
/*   Updated: 2021/11/21 10:18:02 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	intlen(long int a)
{
	int	i;

	i = 0;
	if (a <= 0)
		i++;
	while (a)
	{
		i++;
		a = a / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*ptr;
	int			len;
	long int	a;

	a = (long int)n;
	len = intlen(a);
	ptr = (char *)malloc(sizeof(char) * len + 1);
	if (ptr == NULL)
		return (NULL);
	if (a == 0)
		ptr[0] = '0';
	if (a < 0)
	{
		ptr[0] = '-';
		a = a * -1;
	}
	ptr[len] = '\0';
	while (a > 0)
	{
		len--;
		ptr[len] = (a % 10) + '0';
		a = a / 10;
	}
	return (ptr);
}
