/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:35:23 by kpolatci          #+#    #+#             */
/*   Updated: 2023/12/23 08:10:52 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*create_env(char *str)
{
	char	*new_env;
	int		new_i;
	int		str_i;
	int		temp;

	new_env = malloc(sizeof(char) * count_for_env(str) + 1);
	new_i = 0;
	str_i = 0;
	while (str[str_i])
	{
		if (str[str_i] == '\'' || str[str_i] == '\"' || 
			str[str_i] == '$')
			copy_env(str, new_env, &new_i, &str_i);
		else
			new_env[new_i++] = str[str_i++];
	}
	new_env[new_i] = '\0';
	return (new_env);
}

void	copy_env(char *str, char *new_env, int *new_i, int *str_i)
{
	char	**g_env;
	char	*new_str;

	g_env = (char **)malloc(sizeof(char *) * 4);
	g_env[0] = "HOME=/home/kpolatci";
	g_env[1] = "USER=kpolatci";
	g_env[2] = "TERM_PROGRAM=vscode";
	g_env[3] = 0;

	int		temp;
	char	*temp_str;
	if (str[*str_i] == '\'')
	{
		temp = *str_i;
		pass_quotes(str, str_i, str[*str_i]);
		ft_strlcpy(str, (new_env + *new_i), (*str_i) - temp);
		(*new_i) += (*str_i) - temp;
	}
	else if (str[*str_i] == '\"')
	{
		new_env[(*new_i)++] = str[(*str_i)++];
		while (str[*str_i] != '\"')
		{
			if (str[*str_i] == '$')
			{
				temp_str = dollar_substr(str, *str_i);
				temp_str = dollar_value(temp_str, g_env);
				ft_strlcpy(temp_str, (new_env + *new_i), ft_strlen(temp_str));
				(*new_i) += ft_strlen(temp_str);
				(*str_i)++;
				while (!is_special_char(str[(*str_i)]) && str[*str_i])
					(*str_i)++;
			}
			new_env[(*new_i)++] = str[(*str_i)++];
		}
		new_env[(*new_i)++] = str[(*str_i)++];
	}
	else if (str[*str_i] == '$')
	{
		temp_str = dollar_substr(str, *str_i);
		temp_str = dollar_value(temp_str, g_env);
		ft_strlcpy(temp_str, (new_env + *new_i), ft_strlen(temp_str));
		(*new_i) += ft_strlen(temp_str);
		(*str_i)++;
		while (!is_special_char(str[*str_i]) && str[*str_i])
			(*str_i)++;
	}
}