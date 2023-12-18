/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:49:41 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:49:41 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else if (dst > src)
	{
		while (n--)
			*((unsigned char *)(dst + n)) = *((unsigned char *)(src + n));
	}
	return (dst);
}

/*
#include <stdio.h>
int main() 
{
	// memcpy'den tek farkı: tekrar binecek durumlarda (src < dest) n kadar ileri gidip tersten kopyalama yapıyor.
    char str1[] = "acikkaynakplatform";
	char str2[] = "acikkaynakplatform";
	printf("%s\n", ft_memcpy(str1 + 4, str1 + 2, 6));
    printf("%s\n", ft_memmove(str2 + 4, str2 + 2, 6));

    return 0;
}*/