/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 20:41:49 by kpolatci          #+#    #+#             */
/*   Updated: 2024/02/27 14:50:13 by kpolatci         ###   ########.fr       */
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
		if (!parser->prev)
			printf("(null)");
		if ((parser->prev))
			printf("prev: %s			", parser->prev->str);
		printf("kendisi: %s 			\n", parser->str);
		parser = parser->next;
	}
}

void	ft_error(void)
{
	printf("Error!");
	exit(1);
}

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void 	ft_print_cmd()
{
	while (g_glbl.cmd)
		{
			while (g_glbl.cmd->exec)
			{
				printf("exec:%s\n", g_glbl.cmd->exec->value);
				g_glbl.cmd->exec = g_glbl.cmd->exec->next;
			}
			while (g_glbl.cmd->redirect)
			{
				printf("redire:%s\n", g_glbl.cmd->redirect->value);
				g_glbl.cmd->redirect = g_glbl.cmd->redirect->next;
			}
			g_glbl.cmd = g_glbl.cmd->next;
			if (g_glbl.cmd)
				printf("------------PIPE------------\n");
		}
}