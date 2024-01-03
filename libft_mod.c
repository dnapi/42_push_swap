/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apimikov <apimikov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 06:58:05 by apimikov          #+#    #+#             */
/*   Updated: 2024/01/03 07:35:48 by apimikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// modified version of strjoin
char	*ft_strjoin_mod(char const *s1, char const *s2, char c)
{
	size_t	len;
	size_t	i;
	char	*pnt;

	if (!s1 || ! s2)
		return (NULL);
	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	pnt = malloc(len + 1);
	if (!pnt)
		return (NULL);
	while (i < len && s1[i])
	{
		pnt[i] = s1[i];
		i++;
	}
	pnt[i++] = c;
	while (i < len && *s2)
		pnt[i++] = *s2++;
	pnt[i] = '\0';
	return (pnt);
}

// this is modied version of ft_atoi in libft, int -> long
long	ft_atoil(const char *str)
{
	long	sign;
	long	answ;
	long	llong_max;

	llong_max = ((unsigned long)(-1)) / 2;
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
