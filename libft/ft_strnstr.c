/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:02:11 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 17:02:11 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	i;

	i = 0;
	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	while (haystack[i] && needle_len <= len)
	{
		if (ft_strncmp(&haystack[i], needle, needle_len) == 0)
			return ((char *)&haystack[i]);
		i++;
		len--;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	char a[] = "beyza";
	char b[] = "ey";

	printf("%s,\n", ft_strnstr(a, b, 0));
    printf("%s,\n", ft_strnstr(a, b, 1));
    printf("%s,\n", ft_strnstr(a, b, 2));
    printf("%s,\n", ft_strnstr(a, b, 3));
    printf("%s,\n", ft_strnstr(a, b, 4));
	return 0;
}*/