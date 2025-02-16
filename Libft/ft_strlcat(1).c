/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:55:15 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:55:15 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dlen;
	unsigned int	slen;

	i = 0;
	j = 0;
	while (dest[j] != '\0')
	{
		j++;
	}
	dlen = j;
	slen = ft_strlen(src);
	if (size == 0 || size <= dlen)
		return (slen + size);
	while (src[i] != '\0' && i < size - dlen - 1)
	{
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dlen + slen);
}

/*
#include <stdio.h>
int main()
{
    char dest[20] = "Kursat Polatci";
	char src[] = "Nbr?";

	printf("%zu - %s\n", ft_strlcat(dest, src, 28), dest);

    char dest1[] = "Kursat";
	char src1[] = "Polatci";

    printf("%zu - %s\n", ft_strlcat(dest1, src1, 9), dest1);

    char dest2[] = "Hey";
	char src2[] = "Naber";

    printf("%zu - %s\n", ft_strlcat(dest2, src2, 9), dest2);
	return 0;
}*/