/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:46:09 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:46:09 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	return (lst);
}

/*
#include <stdio.h>
void print_content(void *content)
{
  printf("%s\n",(char*)content);
}

int main()
{
    t_list *lst1 = ft_lstnew(ft_strdup("Merhaba"));
    t_list *lst2 = ft_lstnew(ft_strdup("Nasilsin"));
    t_list *lst3 = ft_lstnew(ft_strdup("İyisin"));

    ft_lstadd_back(&lst1,lst2);
    ft_lstadd_back(&lst1,lst3);

    ft_lstiter(lst1,&print_content);

    t_list *last = ft_lstlast(lst1);

    printf("Son elemanın content'i: %s\n",last -> content);
}*/