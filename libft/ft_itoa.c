/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:35:46 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:35:46 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(int n)
{
	size_t	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	size_t		len;
	const char	*digits;

	digits = "0123456789";
	len = get_digits(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n > 0)
			str[len--] = digits[n % 10];
		else
			str[len--] = digits[n % 10 * -1];
		n /= 10;
	}
	return (str);
}

/*
#include <stdio.h>
int main() 
{
	int	a = -6;
	printf("%s\n", ft_itoa(a));

    int	b = -52352345;
	printf("%s\n", ft_itoa(b));

    int	c = 123123423;
	printf("%s\n", ft_itoa(c));

    int	d = 5;
	printf("%s\n", ft_itoa(d));

	int	e = 0;
	printf("%s\n", ft_itoa(e));
	return(0);
}*/