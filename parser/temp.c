/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:41:49 by kpolatci          #+#    #+#             */
/*   Updated: 2023/10/23 23:57:42 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_print_split(char **str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		printf("%s\n", str[index]);
		index++;
	}
}

void	ft_printlist(t_parser *parser)
{
	while (parser != NULL)
	{
		printf("%s\n", parser->str);
		parser = parser->next;
	}
}

void	ft_error(void)
{
	printf("Error!");
	exit(1);
}
