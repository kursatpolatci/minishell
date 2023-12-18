/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:15:50 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/15 04:12:33 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *))
{
	t_list	*first;
	t_list	*new;

	if (lst == NULL || f == NULL)
		return (NULL);
	first = NULL;
	while (lst)
	{
		new = ft_lstnew((*f)(lst->content));
		if (!new)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, new);
		lst = lst->next;
	}
	return (first);
}

/*
#include <stdio.h>
void *f(void *content)
{
    return ft_memset(content,'+',3);
}

void del(void *content)
{
    free(content);
}

void del_for_lstclear(void *content)
{
    printf("%s Siliniyor...\n",(char *) content);
    free(content);
}

void print_content(void *content)
{
    printf("%s\n",(char *)content);
}

int main()
{
    t_list *lst = ft_lstnew(ft_strdup("İzmir"));
    ft_lstadd_back(&lst,ft_lstnew(ft_strdup("Istanbul")));
    ft_lstadd_back(&lst,ft_lstnew(ft_strdup("Ankara")));
    
    printf("lstmap oncesi: \n");
    ft_lstiter(lst,&print_content);
    
    t_list *new = ft_lstmap(lst,&f,&del);
    printf("lstmap sonrasi olan yeni Linked List: \n");
    ft_lstiter(lst,&print_content);

    printf("lstclear sonrasi: \n");
    ft_lstclear(&(new -> next),&del_for_lstclear);
    ft_lstiter(new,&print_content);
}*/