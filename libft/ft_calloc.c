/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:38:03 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 15:38:03 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, size * count);
	return (p);
}

/*
#include <stdio.h>
int    main()
{
    int *ptr1 = (int *)malloc(sizeof(int) * 4);
    ptr1[0] = 1;
    ptr1[1] = 2;
    ptr1[2] = 3;
    ptr1[3] = 4;

    char *ptr2 = ft_strdup("Kursat Polatci");

    printf("%d %d %d %d\n",ptr1[0],ptr1[1],ptr1[2],ptr1[3]);
    printf("%s\n",ptr2);


    ptr1 = (int *)ft_calloc(4,sizeof(int));
    ptr2 = (char *)ft_calloc(14,sizeof(char));

    printf("%d %d %d %d\n",ptr1[0],ptr1[1],ptr1[2],ptr1[3]);
    printf("%d\n",*ptr2);
}
*/
