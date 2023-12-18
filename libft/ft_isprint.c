/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:06:38 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 17:06:38 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

/*
#include <stdio.h>
int main()
{
    printf("a -> %d\n",ft_isprint('a'));
    printf("A -> %d\n",ft_isprint('A'));
    printf("5 -> %d\n",ft_isprint('5'));
    printf("& -> %d\n",ft_isprint('&'));
}*/