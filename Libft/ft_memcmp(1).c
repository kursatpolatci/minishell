/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:48:25 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:48:25 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*t1;
	unsigned const char	*t2;

	t1 = (unsigned const char *)s1;
	t2 = (unsigned const char *)s2;
	i = 0;
	while (i < n)
	{
		if (t1[i] != t2[i])
			return (t1[i] - t2[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*s1 = "bubir";
	char	*s2 = "buiki";
    
    char    *p1 = "sa";
    char    *p2 = "sa";

    char    *t1 = "kaserlan";
    char    *t2 = "kas";

    printf("%d\n",ft_memcmp(s1,s2,5));
    printf("%d\n",ft_memcmp(s1,s2,3));
    printf("%d\n",ft_memcmp(s1,s2,0));
    printf("%d\n",ft_memcmp(s1,s2,6));
    printf("%d\n",ft_memcmp(s1,s2,10));


    printf("----------------\n");


    printf("%d\n",ft_memcmp(p1,p2,1));
    printf("%d\n",ft_memcmp(p1,p2,5));
    printf("%d\n",ft_memcmp(p1,p2,3));


    printf("----------------\n");


    printf("%d\n",ft_memcmp(t1,t2,1));
    printf("%d\n",ft_memcmp(t1,t2,3));
    printf("%d\n",ft_memcmp(t1,t2,4));
    printf("%d\n",ft_memcmp(t1,t2,7));

    printf("----------------\n");

    int *dizi1 = (int *)malloc(sizeof(int) * 3);
    dizi1[0] = 1;
    dizi1[1] = 2;
    dizi1[2] = 3;

    int *dizi2 = (int *)malloc(sizeof(int) * 3);
    dizi2[0] = 1;
    dizi2[1] = 2;
    dizi2[2] = 5;

    printf("%d\n",ft_memcmp(dizi1,dizi2,sizeof(int)*1));
    printf("%d\n",ft_memcmp(dizi1,dizi2,sizeof(int)*2));
    printf("%d\n",ft_memcmp(dizi1,dizi2,sizeof(int)*3));
    printf("%d\n",ft_memcmp(dizi1,dizi2,sizeof(int)*4));
}*/