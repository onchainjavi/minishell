/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islonglong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarinel <jmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:56:55 by jmarinel          #+#    #+#             */
/*   Updated: 2023/12/13 15:57:29 by jmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_islonglong(const char *str)
{
	long long	num;
	int			i;
	int			sign;	

	num = 0;
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	if (str[i] < '0' || str[i] > '9')
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (num * sign > (LLONG_MAX - (str[i] - '0')) / 10 || \
			num * sign < ((LLONG_MIN) + (str[i] - '0')) / 10)
			return (1);
		num *= 10;
		num += (str[i++] - '0');
	}
	return (0);
}
