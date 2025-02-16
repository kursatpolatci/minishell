/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:04:57 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 17:04:57 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		c -= 32;
	return (c);
}

/*
#include <stdio.h>
int main()
{
    printf("a -> %c\n",ft_toupper('a'));
    printf("A -> %c\n",ft_toupper('A'));
    printf("5 -> %c\n",ft_toupper('5'));
    printf("A -> %c\n",ft_toupper(65));
    printf("a -> %c\n",ft_toupper(97));
}*/