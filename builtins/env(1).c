/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:56:27 by fatturan          #+#    #+#             */
/*   Updated: 2024/02/27 16:16:36 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	arg_counter(t_execute *execute)
{
	int	i;

	i = 0;
	while (execute)
	{
		i++;
		execute = execute->next;
	}
	if (i >= 2)
		return (1);
	else if (i == 1)
		return (-1);
	return (0);
}

int	check_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '=')
			return (-1);
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

int	check_environment(t_execute *execute, int *flag)
{
	if (arg_counter(execute) == 0 || arg_counter(execute) == 1)
	{
		if (arg_counter(execute) == 1 && check_equal(execute->next->value) != 0)
		{
			if (check_equal(execute->next->value) == 1)
				*flag = 1;
			else if (check_equal(execute->next->value) == -1)
			{
				printf("env: setenv %s: Invalid argument\n",
					execute->next->value);
				return (1);
			}
		}
		else
		{
			printf("env: %s: No such file or directory\n",
				execute->next->value);
			return (1);
		}
	}
	return (0);
}

void	ft_env(t_execute *exec)
{
	int		i;
	char	**tmp;
	int		flag;

	i = 0;
	flag = 0;
	if (check_environment(exec, &flag))
		return ;
	while (g_glbl.env[i])
	{
		tmp = ft_split(g_glbl.env[i], '=');
		if (tmp[0] && tmp[1])
			printf("%s=\"%s\"\n", tmp[0], tmp[1]);
		if (!tmp[1])
			printf("%s\"\"\n", tmp[0]);
		i++;
		ft_free_split(tmp);
	}
	if (flag == 1)
		printf("%s\n", exec->next->value);
	ft_fill_path();
}
