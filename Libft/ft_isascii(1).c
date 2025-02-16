/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:15:55 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:15:55 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*
#include <stdio.h>
int main()
{
    printf("a -> %d\n",ft_isascii('a'));
    printf("A -> %d\n",ft_isascii('A'));
    printf("5 -> %d\n",ft_isascii('5'));
    printf("& -> %d\n",ft_isascii('&'));
}*/