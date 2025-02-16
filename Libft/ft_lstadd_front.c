/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:36:54 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:36:54 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new->next = *lst;
	*lst = new;
}

/*
#include<stdio.h>
int main()
{
	t_list *lst1 = ft_lstnew(ft_strdup("Polatci")); // listenin başı
	t_list *lst2 = ft_lstnew(ft_strdup("Kursat")); // başa gelecek yeni node
	t_list *lst3 = ft_lstnew(ft_strdup("Hos geldin!")); // en son başa gelecek yeni node
	ft_lstadd_front(&lst1, lst2);
	ft_lstadd_front(&lst1, lst3);

	printf("%s %s %s\n", lst1->content, lst1->next->content, lst1->next->next->content);
}*/