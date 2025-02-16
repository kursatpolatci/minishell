/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:48:42 by kpolatci          #+#    #+#             */
/*   Updated: 2024/02/24 14:31:27 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//void	close_heredoc_fd(t_command *cmd)
//{
//	if (contain_heredoc() && cmd->heredoc_fd[0] > 2)
//		close(cmd->heredoc_fd[0]);
//}

void	ft_close_all_fd(void)
{
	t_command	*cmd;

	cmd = g_glbl.cmd;
	while (cmd)
	{
		//close_heredoc_fd(cmd);
		if (cmd->fd[0] > 2)
			close(cmd->fd[0]);
		if (cmd->fd[1] > 2)
			close(cmd->fd[1]);
		cmd = cmd->next;
	}
}

void	directory_err(char *str)
{
	//errno = 126;
	write(2, "minishell: ", 11);
	write(2, str, ft_strlen(str));
	write(2, ": is a directory\n", 17);
	//if (!is_parent())
	//	exit(1); // errno dönecek
}