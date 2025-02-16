/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:56:24 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:56:24 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>
char	f1(unsigned int i, char s)
{
	if (ft_isalpha(s))
		return s + i;
	return s;
}

char f2(unsigned int i, char s)
{
    return '*';
}

int main() {
	char b[] = "Kursat Polatci";
	printf("%s\n", ft_strmapi(b, &f1));

    printf("------------------\n");

	char c[] = "Kursat Polatci";
	printf("%s\n", ft_strmapi(c, &f2));
}*/