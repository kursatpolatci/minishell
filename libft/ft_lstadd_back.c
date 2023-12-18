/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:37:41 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:37:41 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

/*
#include <stdio.h>
int main()
{
    t_list *lst1 = ft_lstnew(ft_strdup("Kursat")); // strdup yerine direkt "Kursat" yazsaydım eğer stack'ten bir yer vermiş olacaktım ve "Kursat" değerini asla değiştiremezdim. çünkü stack'te açılan yerler read-only'dir.
    t_list *lst2 = ft_lstnew(ft_strdup("Matematik"));
    t_list *lst3 = ft_lstnew(ft_strdup("Fizik"));

    ft_lstadd_back(&lst1,lst2);
    ft_lstadd_back(&lst1,lst3);

    while(lst1 != NULL)
    {
      printf("%s\n",lst1 -> content);
      lst1 = lst1 -> next;
    }
}*/