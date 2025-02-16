/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:04:18 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 17:04:18 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, size_t len)
{
	char	*substr;
	size_t	size;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_strlen(s + start);
	if (size < len)
		len = size;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, (char *)s + start, len + 1);
	return (substr);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*str = "Kursat Polatci Hola!";

	char	*ret = ft_substr(&str[3], 0, 5);
	printf("%s -> %s\n", str, ret);

    printf("----------------------\n");

	char	*ret1 = ft_substr(str, 14, 10);
	printf("%s -> %s\n", str, ret1);

    printf("----------------------\n");

	char	*ret2 = ft_substr(str, 0, 10);
	printf("%s -> %s\n", str, ret2);

	printf("----------------------\n");

	char	*ret3 = ft_substr(str, 50, 10);
	printf("%s -> %s\n", str, ret3);

	printf("----------------------\n");

	char	*ret4 = ft_substr(str, 10, 6);
	printf("%s -> %s\n", str, ret4);

	printf("----------------------\n");

	char	*ret5 = ft_substr(str, 6, 10);
	printf("%s -> %s\n", str, ret5);

	printf("----------------------\n");

	char	*ret6 = ft_substr(str, 0, 0);
	printf("%s -> %s\n", str, ret6);
}*/