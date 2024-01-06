/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boxing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fa.betulturan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:32:45 by fatturan          #+#    #+#             */
/*   Updated: 2024/01/05 19:12:52 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_send_box(t_command *cmd, t_parser **main)
{
	if((*main)->type == ARG)
		cmd->exec = ft_exec_box(&cmd->exec, *main);
	else if((*main)->type == OUTPUT_R || (*main)->type == INPUT_R)
		cmd->redirect = ft_redirect_box(&cmd->redirect, *main);
	else if((*main)->type == D_OUTPUT_R || (*main)->type == D_OUTPUT_R)
		cmd->redirect = ft_redirect_box(&cmd->redirect, *main);
}

void	ft_add_box(t_command *cmd)
{
	t_command *prev;

	prev = g_glbl.cmd;
	if(prev == NULL)
		prev = g_glbl.cmd;
	else
	{
		while(prev->next)
			prev = prev->next;
		prev->next = cmd;
		cmd->prev = prev;
	}
}

t_command	*ft_init_cmd(void)
{
	t_command	*new_cmd;

	new_cmd = malloc(sizeof(t_command));
	new_cmd->next = NULL;
	new_cmd->prev = NULL;
	return(new_cmd);
}

int	ft_cmd_box(t_parser *main)
{
	t_command *cmd;

	g_glbl.cmd = NULL;
	cmd = NULL;
	while(main)
	{
		if (main->type == PIPE || main->str[0])
		{
			if (main->type == PIPE)
				main = main->next;
			cmd = ft_init_cmd();
			ft_add_box(cmd);
			g_glbl.cmd++;
		}
		ft_send_box(cmd, &main);
		main = main->next;
	}
	return(0);
}