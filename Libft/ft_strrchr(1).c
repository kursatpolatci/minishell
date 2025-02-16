/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:03:21 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 17:03:21 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*start;

	start = (char *)s;
	while (*s)
		s++;
	while (s >= start)
	{
		if (*((char *)s) == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int main()
{
	const char s[] = "Polatci Kursat";
	printf("%s,\n", ft_strrchr(s, 'z'));
    printf("%s,\n", ft_strrchr(s, 'b'));
	printf("%s,\n", ft_strrchr(s, ' '));
    printf("%s,\n", ft_strrchr(s, 'a'));

	return 0;
}*/