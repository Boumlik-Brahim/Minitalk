/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbrahim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:40:16 by bbrahim           #+#    #+#             */
/*   Updated: 2021/11/21 10:10:45 by bbrahim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n'
		|| c == '\r' || c == '\v'
		|| c == ' ' || c == '\f')
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		res;
	int		sign;
	size_t	i;

	res = 0;
	i = 0;
	sign = 1;
	while (ft_is_space(str[i]) != 0)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}
