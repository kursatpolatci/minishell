/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:00:38 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:00:38 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int	main(void)
{
    printf("a -> %d\n",ft_isalnum('a'));
    printf("A -> %d\n",ft_isalnum('A'));
    printf("5 -> %d\n",ft_isalnum('5'));
    printf("& -> %d\n",ft_isalnum('&'));
}*/