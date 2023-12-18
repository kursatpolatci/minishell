/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:46:40 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:46:40 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
void print_content(void *content)
{
    printf("%s\n",(char*) content);
}

int main()
{
    t_list *lst1 = ft_lstnew(ft_strdup("Kimya"));
    t_list *lst2 = ft_lstnew(ft_strdup("Fizik"));
    t_list *lst3 = ft_lstnew(ft_strdup("Biyoloji"));

    ft_lstadd_back(&lst1,lst2);
    ft_lstadd_back(&lst1,lst3);


    int size = ft_lstsize(lst1);
    ft_lstiter(lst1,&print_content);
    printf("Boyut: %d\n",size);
}*/