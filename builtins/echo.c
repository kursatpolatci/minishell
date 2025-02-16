/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:56:23 by fatturan          #+#    #+#             */
/*   Updated: 2024/02/27 14:58:11 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_execute	*ft_check_n(t_execute *exec, int *flag)
{
	int	i;

	while (exec != NULL)
	{
		i = 0;
		while (exec->value[i])
		{
			if (i == 0 && exec->value[0] != '-')
				break ;
			else if (i != 0 && exec->value[i] != 'n')
				break ;
			i++;
		}
		if (exec->value[i] == '\0')
			*flag = 1;
		if (exec->value[i])
			return (exec);
		exec = exec->next;
	}
	return (exec);
}

void	ft_echo(t_command *cmd)
{
	t_execute	*temp;
	int			flag;

	flag = 0;
	temp = cmd->exec->next;
	temp = ft_check_n(temp, &flag);
	if (cmd != NULL)
	{
		while (cmd != NULL && temp != NULL)
		{
			printf("%s", temp->value);
			temp = temp->next;
		}
		if (!flag)
			printf("\n");
	}
}