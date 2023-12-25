#include "push_swap.h"

/// ###     LIBFT        #####

// this is modied version of ft_atoi in libft, int -> long
long long	ft_atoi(const char *str)
{
	long long	sign;
	long long	answ;
	long long	llong_max;

	llong_max = ((unsigned long long)(-1)) / 2;
//	llong_max = LLONG_MAX;
//	printf("%lld\n",llong_max);
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
