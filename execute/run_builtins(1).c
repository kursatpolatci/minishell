/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_builtins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:48:54 by fatturan          #+#    #+#             */
/*   Updated: 2024/02/27 18:06:01 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_wait_cmd(void)
{
	t_command	*cmd;

	cmd = g_glbl.cmd;
	ft_close_all_fd();
	while (cmd != NULL)
	{
		if (cmd->p_pid != -1)
		{
			waitpid(cmd->p_pid, 0, 0);
			//if (WIFEXITED(errno))
			//	g_glbl.erorno = WEXITSTATUS(errno);
			//else if (WIFSIGNALED(errno))
			//	g_glbl.erorno = 128 + WTERMSIG(errno);
		}
		cmd = cmd->next;
	}
}

int	ft_process_builtins(t_command *cmd)
{
	t_command	*tmp_cmd;

	tmp_cmd = cmd;
	if (tmp_cmd == NULL)
		return (0);
	else if (ft_is_equal(cmd->exec->value, "echo"))
		ft_echo(tmp_cmd);
	else if (ft_is_equal(cmd->exec->value, "cd"))
		ft_cd(tmp_cmd);
	else if (ft_is_equal(cmd->exec->value, "env"))
		ft_env(tmp_cmd->exec);
	else if (ft_is_equal(cmd->exec->value, "exit"))
		ft_exit(tmp_cmd);
	else if (ft_is_equal(cmd->exec->value, "export"))
		ft_export(tmp_cmd);
	else if (ft_is_equal(cmd->exec->value, "unset"))
		ft_unset(tmp_cmd);
	else if (ft_is_equal(cmd->exec->value, "pwd"))
		ft_pwd();
	else
		return (0);
	return (1);
}

void	ft_run_builtins(t_command *cmd)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	if (!ft_redi_outputs(cmd))
		return ;
	ft_process_builtins(cmd);
	dup2(in, 0);
	dup2(out, 1);
	close(in);
	close(out);
}

int	ft_is_builtin(t_command *cmd)
{
	if (ft_is_equal(cmd->exec->value, "echo"))
		return (1);
	else if (ft_is_equal(cmd->exec->value, "cd"))
		return (1);
	else if (ft_is_equal(cmd->exec->value, "env"))
		return (1);
	else if (ft_is_equal(cmd->exec->value, "exit"))
		return (1);
	else if (ft_is_equal(cmd->exec->value, "export"))
		return (1);
	else if (ft_is_equal(cmd->exec->value, "pwd"))
		return (1);
	else if (ft_is_equal(cmd->exec->value, "unset"))
		return (1);
	return (0);
}

void	ft_fill_heredoc(void)
{
	t_command	*cmd;
	t_redirect	*redir;

	cmd = g_glbl.cmd;
	while (cmd)
	{
		redir = cmd->redirect;
		while (redir)
		{
			if (redir->type == D_OUTPUT_R)
				ft_heredoc(cmd->heredoc_fd, redir->value);
			redir = redir->next;
		}
		cmd = cmd->next;
	}
}

void	ft_process_cmd(void)
{
	t_command	*cmd;

	cmd = g_glbl.cmd;
	if (!cmd)
		return ;
	ft_fill_heredoc();
	if (cmd->exec && g_glbl.cmd_count == 1 && ft_is_builtin(cmd))
	{
		ft_run_builtins(cmd);
		cmd = cmd->next;
	}
	while (cmd)
	{
		ft_action(cmd);
		cmd = cmd->next;
	}
	ft_wait_cmd();
}
