/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:44:02 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:44:02 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

/*
#include <stdio.h>
void f_del(void *content)
{
    printf("%s Siliniyor...\n",(char *)content);
	free(content);
}

void print_content(void *content)
{
    printf("%s\n",(char *)content);
}

int main()
{
    t_list *start = ft_lstnew(ft_strdup("Mustafa"));
    t_list *student1 = ft_lstnew(ft_strdup("Kemal"));
    t_list *student2 = ft_lstnew(ft_strdup("Ataturk"));
    t_list *student3 = ft_lstnew(ft_strdup("Lider"));
    t_list *student4 = ft_lstnew(ft_strdup("Laik"));


    ft_lstadd_front(&start,student1);
    ft_lstadd_front(&start,student2);
    ft_lstadd_front(&start,student3);
    ft_lstadd_front(&start,student4);

    ft_lstiter(start,&print_content);

    ft_lstclear(&(start -> next -> next),&f_del);

    ft_lstiter(start,&print_content);
}*/