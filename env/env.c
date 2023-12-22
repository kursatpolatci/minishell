/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:35:23 by kpolatci          #+#    #+#             */
/*   Updated: 2023/12/22 09:27:30 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_special_char(char c)
{
	if ((c >= 32 && c <= 47) || (c >= 58 && c <= 64) || 
		(c >= 91 && c <= 96 && c != 95) || (c >= 123 && c <= 126))
		return (1);
	return (0);
}

char	*dollar_substr(char *str, int index)
{
	int	inception;

	index++;
	inception = index;

	if (is_special_char(str[index]) || !str[index])
		return (ft_strdup("$"));
	while (!is_special_char(str[index]) && str[index])
		index++;
	return (ft_substr(str, inception, index - 1));
}

char	*dollar_value(char *dol_sub, char **env)
{
	int	i_env;
	int	i;

	i_env = 0;
	if (dol_sub[0] == '$')
		return (ft_strdup("$"));
	while (env[i_env])
	{
		i = 0;
		while (dol_sub[i])
		{
			if (env[i_env][i] != dol_sub[i])
				break ;
			i++;
		}
		if (!dol_sub[i])
			return (ft_substr(env[i_env], ++i, ft_strlen(env[i_env]) - 1));
		i_env++;
	}
	return (NULL);
}
