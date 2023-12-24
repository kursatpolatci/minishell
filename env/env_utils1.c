/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 06:01:34 by kpolatci          #+#    #+#             */
/*   Updated: 2023/12/24 07:09:57 by kpolatci         ###   ########.fr       */
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
		if (str[index] == '\'')
			count_for_single_quo(str, str[index], &index, &len);
		else if (str[index] == '\"')
			count_for_double_quo(str, str[index], &index, &len);
		else if (str[index] == '$')
			count_dollar(str, &index, &len);
		else
		{
			index++;
			len++;
		}
	}
	return (len);
}

void	count_dollar(char *str, int *index, int *len)
{
	char	**t_glb;

	t_glb = (char **)malloc(sizeof(char *) * 4);
	t_glb[0] = "HOME=/home/kpolatci";
	t_glb[1] = "USER=kpolatci";
	t_glb[2] = "TERM_PROGRAM=vscode";
	t_glb[3] = 0;
	char	*new_str;

	new_str = dollar_substr(str, *index);
	new_str = dollar_value(new_str, t_glb);
	(*len) += ft_strlen(new_str);
	(*index)++;
	while (!is_special_char(str[*index]) && str[*index])
		(*index)++;
}

void	count_for_single_quo(char *str, char c, int *index, int *len)
{
	int	temp;

	if (c == '\'')
	{
		temp = *index;
		pass_quotes(str, index, c);
		(*len) += (*index) - temp;
	}
}

void	count_for_double_quo(char *str, char c, int *index, int *len)
{
	if (c == '\"')
	{
		(*index)++;
		(*len)++;
		while (str[*index] != '\"' && str[*index])
		{
			if (str[*index] == '$')
				count_dollar(str, index, len);
			if (str[*index] != '\"')
			{
				(*index)++;
				(*len)++;
			}
		}
		(*index)++;
		(*len)++;
	}
}
