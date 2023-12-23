/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:01:34 by kpolatci          #+#    #+#             */
/*   Updated: 2023/12/23 05:51:46 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	count_for_env(char *str)
{
	int	len;
	int	index;

	index = 0;
	len = 0;
	while (str[index])
	{
		if (str[index] == '\'' || str[index] == '\"' || str[index] == '$')
			count_for_env_exp(str, str[index], &index, &len);
		else
		{
			index++;
			len++;
		}
	}
	return (len);
}

void	count_for_env_exp(char *str, char c, int *index, int *len)
{
	int	temp;

	if (c == '\'')
	{
		temp = *index;
		pass_quotes(str, index, c);
		(*len) += (*index) - temp;
	}
	else if (c == '\"')
	{
		(*index)++;
		(*len)++;
		while (str[*index] != '\"' && str[*index])
		{
			if (str[*index] == '$')
				count_dollar(str, index, len);
			(*index)++;
			(*len)++;
		}
		(*index)++;
		(*len)++;
	}
	else if (c == '$')
		count_dollar(str, index, len);
}

void	count_dollar(char *str, int *index, int *len)
{
	char	**g_env;
	char	*new_str;

	g_env = (char **)malloc(sizeof(char *) * 4);
	g_env[0] = "HOME=/home/kpolatci";
	g_env[1] = "USER=kpolatci";
	g_env[2] = "TERM_PROGRAM=vscode";
	g_env[3] = 0;

	new_str = dollar_substr(str, *index);
	new_str = dollar_value(new_str, g_env);
	(*len) += ft_strlen(new_str);
	(*index)++;
	while (!is_special_char(str[*index]) && str[*index])
		(*index)++;
}
