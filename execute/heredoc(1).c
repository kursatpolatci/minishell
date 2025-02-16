/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:44:47 by kpolatci          #+#    #+#             */
/*   Updated: 2024/02/27 18:16:08 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_heredoc(void)
{
	t_redirect	*radir;

	radir = g_glbl.cmd->redirect;
	while (radir)
	{
		if (radir->type == D_INPUT_R)
			return (1);
		if (radir->next)
			radir = radir->next;
		else
			break ;
	}
	return (0);
}

void	ft_heredoc_route(t_command *cmd)
{
	dup2(cmd->heredoc_fd[0], 0);
	if (cmd->next != NULL)
		dup2(cmd->fd[1], 1);
}

int	ft_closing_words(char *str1, char *str2)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	if (!str1[0] && !str2[0])
		return (1);
	while (str1[j])
	{
		k = 0;
		if (str1[j] == str2[k])
		{
			if (ft_sub_equal(str1, str2, &j, &k))
				return (1);
		}
		if (str1[j] != '\0')
			j++;
	}
	return (0);
}
void	ft_get_heredoc(char *endline, int *fd)
{
	char	*input;

	//signal(SIGINT, interreput);
	while (1)
	{
		input = readline("heredoc>> ");
		if (ft_closing_words(input, endline)
			&& ft_strlen(input) == ft_strlen(endline))
		{
			free(input);
			exit(1);
		}
		write(fd[1], input, ft_strlen(input));
		write(fd[1], "\n", 1);
		free(input);
	}
}

void	heredoc(int *fd, char *endline)
{
	int	pid;
	int	status;

	if (pipe(fd) < 0)
		return (perror("minishell"));
	pid = fork();
	if (pid == 0)
	{
		ft_get_heredoc(endline, fd);
		close(fd[1]);
	}
	waitpid(pid, &status, 0);
	if (status == 1024) //başarılı
		g_glbl.heredoc = 1;
	else
		g_glbl.heredoc = 0;
	close(fd[1]);
}