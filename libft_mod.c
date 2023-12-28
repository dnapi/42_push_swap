/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apmikov <apmikov@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 04:23:10 by apmikov           #+#    #+#             */
/*   Updated: 2023/12/28 04:23:12 by apmikov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// this is modied version of ft_atoi in libft, int -> long
long long	ft_atoi(const char *str)
{
	long long	sign;
	long long	answ;
	long long	llong_max;

	llong_max = ((unsigned long long)(-1)) / 2;
	sign = 1;
	answ = 0;
	while ((8 < *str && *str < 14) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while ('0' <= *str && *str <= '9')
	{
		if (answ > llong_max / 10)
			return ((sign > 0) * (-1));
		answ = answ * 10;
		if (answ > llong_max - (*str - '0'))
			return ((sign > 0) * (-1));
		answ = answ + ((*str++) - '0');
	}
	return (sign * answ);
}

int	ft_strlen(const char *s)
{
	char	*pnt;

	pnt = (char *)s;
	while (*pnt)
		pnt++;
	return (pnt - s);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	else
		return ((char *)0);
}

/// ###    end of  LIBFT        #####
