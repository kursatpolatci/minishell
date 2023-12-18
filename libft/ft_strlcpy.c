/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:55:44 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:55:44 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;
	size_t	len;

	srclen = ft_strlen(src);
	if (dstsize)
	{
		if (srclen >= dstsize)
			len = dstsize - 1;
		else
			len = srclen;
		ft_memcpy(dst, src, len);
		dst[len] = '\0';
	}
	return (srclen);
}

/*
#include <stdio.h>
int main()
{
	char src[] = "selamlar";

	char dest[] = "adak";
	size_t i = ft_strlcpy(dest,src,4);
	printf("%s => Boyut: %zu\n",dest,i);

	printf("----------------------\n");

	char dest2[] = "adak";
	size_t i2 = ft_strlcpy(dest2,src,3);
	printf("%s => Boyut: %zu\n",dest2,i2);

	printf("----------------------\n");

	char dest3[] = "adak";
	size_t i3 = ft_strlcpy(dest3,src,5);
	printf("%s => Boyut: %zu\n",dest3,i3);

	printf("----------------------\n");

	char dest4[] = "adak";
	size_t i4 = ft_strlcpy(dest4,src,8);
	printf("%s => Boyut: %zu\n",dest4,i4);

	printf("----------------------\n");

	char dest5[] = "adak";
	size_t i5 = ft_strlcpy(dest5,src,15);
	printf("%s => Boyut: %zu\n",dest5,i5);
}*/