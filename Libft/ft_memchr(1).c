/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:47:51 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:47:51 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int main()
{
	char *dizi = "Kursat Polatci";
	printf("%p\n", ft_memchr(dizi, ' ', 3));
    printf("%p\n", ft_memchr(dizi, ' ', 6));
    printf("%p\n", ft_memchr(dizi, ' ', 7));
    printf("%p\n", ft_memchr(dizi, ' ', 10));


    printf("-----------------------\n");


    int *array = (int *)malloc(sizeof(int) * 4);
    array[0] = 1;
    array[1] = 2;
    array[2] = 3;
    array[3] = 4;

    printf("%p\n", ft_memchr(array, 3, sizeof(int)*3));
    printf("%p\n", ft_memchr(array, 3, sizeof(int)*6));
    printf("%p\n", ft_memchr(array, 3, sizeof(int)*2));
}*/