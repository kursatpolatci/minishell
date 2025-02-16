/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:04:52 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 17:04:52 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		c += 32;
	return (c);
}

/*
#include <stdio.h>
int main()
{
    printf("a -> %c\n",ft_tolower('a'));
    printf("A -> %c\n",ft_tolower('A'));
    printf("5 -> %c\n",ft_tolower('5'));
    printf("A -> %c\n",ft_tolower(65));
    printf("a -> %c\n",ft_tolower(97));
}*/