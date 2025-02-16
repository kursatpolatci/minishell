/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:45:25 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:45:25 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	del(lst->content);
	free(lst);
}

/*
#include <stdio.h>
void ft_del(void *content)
{
    ft_bzero(content,sizeof(content));
}

void print_content(void *content)
{
    printf("%s\n",(char *)content);
}

int main()
{
    char s[] = "start";
    char s1[] = "student 1";
    char s2[] = "student 2";
    char s3[] = "student 3";

    t_list *start = ft_lstnew(s);
    t_list *student1 = ft_lstnew(s1);
    t_list *student2 = ft_lstnew(s2);
    t_list *student3 = ft_lstnew(s3);

    ft_lstadd_back(&start,student1);
    ft_lstadd_back(&start,student2);
    ft_lstadd_back(&start,student3);

    ft_lstiter(start,&print_content);

    printf("lstdelone sonrasi: \n");
    ft_lstdelone(student2,ft_del);

    ft_lstiter(start,&print_content);
}*/