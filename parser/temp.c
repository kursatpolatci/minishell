/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fa.betulturan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:41:49 by kpolatci          #+#    #+#             */
/*   Updated: 2024/01/05 22:59:22 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_split(char **str)
{
	int	index;

	index = 0;
	if (!(*str))
		return ;
	while (str[index] != NULL)
	{
		printf("%s\n", str[index]);
		index++;
	}
}

void	ft_printlist(t_parser *parser)
{
	while (parser != NULL)
	{
		printf("%s				", parser->prev);
		printf("%s %p \n", parser->str, parser->str);
		parser = parser->next;
	}
}

void	ft_error(void)
{
	printf("Error!");
	exit(1);
}
