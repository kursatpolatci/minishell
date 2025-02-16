/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:51:42 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:51:42 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	c = (unsigned char)c;
	if (c == 0)
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	const char s[] = "Polatci Kursat";
	printf("%s,\n", ft_strchr(s, 'z'));
    printf("%s,\n", ft_strchr(s, 'b'));
	printf("%s,\n", ft_strchr(s, ' '));
    printf("%s,\n", ft_strchr(s, 'a'));

	return 0;
}*/