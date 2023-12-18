/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:17:24 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:17:24 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
#include <stdio.h>
int main()
{
    printf("a -> %d\n",ft_isdigit('a'));
    printf("A -> %d\n",ft_isdigit('A'));
    printf("5 -> %d\n",ft_isdigit('5'));
    printf("& -> %d\n",ft_isdigit('&'));
    printf("A -> %d\n",ft_isdigit(65));
}*/