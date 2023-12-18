/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:13:02 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:13:02 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*
#include <stdio.h>
int main()
{
    printf("a -> %d\n",ft_isalpha('a'));
    printf("A -> %d\n",ft_isalpha('A'));
    printf("5 -> %d\n",ft_isalpha('5'));
    printf("& -> %d\n",ft_isalpha('&'));
}*/