/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:46:32 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:46:32 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

/*
#include <stdio.h>
int	main(void)
{
	t_list *new = ft_lstnew(ft_strdup("Kursat Polatci"));
	printf("%s\n", (new -> content));

	int b = 5;
	t_list *new2 = ft_lstnew(&b);
	int *a = new2 -> content; // (new2 -> content) pointer to void olduğu için ekrana bastırmam için int bir pointer ile tutmam gerek
	printf("%d\n",*a);
}*/