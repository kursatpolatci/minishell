/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:45:44 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:45:44 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>
void print_content(void *content)
{
    printf("%s :)\n",(char *)content);
}

int main()
{
    t_list *student1 = ft_lstnew(ft_strdup("Kursat Polatci"));
    t_list *student2 = ft_lstnew(ft_strdup("Muhammed Ali"));
    t_list *student3 = ft_lstnew(ft_strdup("Mike Tyson"));

    student1 -> next = student2;
    student2 -> next = student3;
    student3 -> next = NULL;

    ft_lstiter(student1,&print_content);
}*/