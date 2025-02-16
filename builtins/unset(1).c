/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:56:57 by fatturan          #+#    #+#             */
/*   Updated: 2024/02/27 17:05:06 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strncmp1(char *tmp, char *value, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tmp[i] != value[i])
			return (0);
		i++;
	}
	if (tmp[i])
		return (0);
	return (1);
}

char	*ft_before_equal(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '=')
		i++;
	tmp = malloc(sizeof(char) * i + 1);
	while (str[j] && str[j] != '=')
	{
		tmp[j] = str[j];
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}

void	ft_del_exp(char *del)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (g_glbl.export[i] != NULL)
	{
		temp = ft_before_equal(g_glbl.export[i]);
		if (ft_strncmp1(temp, del, ft_strlen(del)))
		{
			j = i;
			free(g_glbl.export[i]);
			while (g_glbl.export[j] != NULL)
			{
				g_glbl.export[j] = g_glbl.export[j + 1];
				j++;
			}
			i = -1;
		}
		i++;
		free(temp);
	}
}

void	ft_del_env(char *del)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (g_glbl.env[i] != NULL)
	{
		temp = ft_before_equal(g_glbl.env[i]);
		if (ft_strncmp1(temp, del, ft_strlen(del)))
		{
			j = i;
			free(g_glbl.env[j]);
			while (g_glbl.env[j] != NULL)
			{
				g_glbl.env[j] = g_glbl.env[j + 1];
				j++;
			}
			i = -1;
		}
		i++;
		free(temp);
	}
}


void	ft_unset(t_command *cmd)
{
	t_execute	*exec;

	exec = cmd->exec;
	exec = exec->next;
	while (exec)
	{
		if (ft_check_err(exec->value, "unset"))
			break ;
		ft_del_env(exec->value);
		ft_del_exp(exec->value);
		exec = exec->next;
	}
}
