/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:19:01 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 15:19:01 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		*((unsigned char *)s) = 0;
		s++;
	}
}

/*
#include <stdio.h>
int	main(void)
{
	char	deneme[7] = "Kursat";
	printf("before : %s\n", deneme);
	ft_bzero(deneme, sizeof(deneme));
	printf("after : %s\n", deneme);

    int dizi[4] = {1,2,3,4};
    printf("%d, %d, %d, %d\n",dizi[0],dizi[1],dizi[2],dizi[3]);
    ft_bzero(dizi,sizeof(int)*4);
    printf("%d, %d, %d, %d\n",dizi[0],dizi[1],dizi[2],dizi[3]);
}*/