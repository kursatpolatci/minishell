/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:56:33 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:56:33 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] < s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else if (s2[i] < s1[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
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


    printf("%d\n",ft_strncmp(s1,s2,5));
    printf("%d\n",ft_strncmp(s1,s2,3));
    printf("%d\n",ft_strncmp(s1,s2,0));

    printf("----------------\n");


    printf("%d\n",ft_strncmp(p1,p2,1));
    printf("%d\n",ft_strncmp(p1,p2,5));
    printf("%d\n",ft_strncmp(p1,p2,3));


    printf("----------------\n");


    printf("%d\n",ft_strncmp(t1,t2,1));
    printf("%d\n",ft_strncmp(t1,t2,4));
    printf("%d\n",ft_strncmp(t1,t2,3));
}*/