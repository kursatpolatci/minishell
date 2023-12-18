/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:18:28 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 15:18:28 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long long int	number;
	int				sign;

	number = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
	{
		number = (number * 10) + (*str - '0') * sign;
		str++;
		if (number > 2147483647)
			return (-1);
		if (number < -2147483648)
			return (0);
	}
	return (number);
}

/*
#include <stdio.h>
int main()
{
    printf("%d\n",ft_atoi("-------12312341"));
    printf("%d\n",ft_atoi(""));
    printf("%d\n",ft_atoi(" "));
    printf("%d\n",ft_atoi(" +123123124"));
    printf("%d\n",ft_atoi(" -+13212234adasd"));
    printf("%d\n",ft_atoi("+---qwq131231"));
    printf("%d\n",ft_atoi("       -1"));
    printf("%d\n",ft_atoi("-------"));
    printf("%d\n",ft_atoi("-a12312312"));
    printf("%d\n",ft_atoi("-123324234"));
    printf("%d\n",ft_atoi("asdasd   -123123"));
    printf("%d\n",ft_atoi("asdassda--1231231"));
    printf("%d\n",ft_atoi("1231234112312123234235235245363463"));
}*/