/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:49:23 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:49:23 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dst != src && n)
	{
		while (i < n)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
int    main(void)
{
    int dizi[4];
    dizi[0] = 1;
    dizi[1] = 2;
    dizi[2] = 3;
    dizi[3] = 4;

    int *array = malloc(sizeof(int) * 4);

    array = ft_memcpy(array,dizi,4 * sizeof(int));

    printf("%d %d %d %d\n",array[0],array[1],array[2],array[3]);

    printf("------------------------------------\n");

    int dizi2[4];
    dizi2[0] = 1;
    dizi2[1] = 2;
    dizi2[2] = 3;
    dizi2[3] = 4;

    int *array2 = malloc(sizeof(int) * 4);

    array2 = ft_memcpy(array2,dizi2,4);

    printf("%d %d %d %d\n",array2[0],array2[1],array2[2],array2[3]);

    printf("------------------------------------\n");

    char str1[5] = "MERA";
    char str2[5] = "asfg";

    char *new = ft_memcpy(str1,str2,3);
    printf("%s\n",new);

    printf("------------------------------------\n");

    char *src = ft_strdup("acikkaynakplatform");
    char *new_src = ft_memcpy(src+4,src+2,6);  // src < dest olduğu zamanlar koplayama işlemi tekrara biner ve tekrarlı karakterler oluşur. bunu önlemek için memmmove fonksiyonumuz var. memmove'de src < dest olduğu zamanlarda n kadar ileri götürüp, tersten kopyalama yapıyoruz. böylelikle tekrarı önlemiş oluyoruz.

    printf("%s\n",new_src);
}*/