/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:24:07 by kpolatci          #+#    #+#             */
/*   Updated: 2023/12/24 06:55:39 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_is_single_quote(char *str)
{
	int	index;

	index = 0;
	while (str[index])
	{
		if (str[index] == '\"')
		{
			index++;
			while (str[index] != '\"' && str[index])
				index++;
			if (!str[index])
				return (1);
		}
		if (str[index] == '\'')
		{
			index++;
			while (str[index] != '\'' && str[index])
				index++;
			if (!str[index])
				return (1);
		}
		index++;
	}
	return (0);
}

char	**ft_create_split(char *str)
{
	char	**split;
	int		split_index;
	int		index;
	int		temp;

	split_index = 0;
	index = 0;
	split = (char **)malloc(sizeof(char *) * ft_argc_count(str) + 1);
	pass_whitespaces(str, &index);
	while (str[index])
	{
		temp = index;
		pass_word(str, &index, &temp);
		split[split_index++] = ft_substr(str, temp - 1, index - 1);
		pass_whitespaces(str, &index);
	}
	split[split_index] = 0;
	return (split);
}

void	check_env(t_parser *parser)
{
	while (parser != NULL)
	{
		if (ft_find_char(parser->str, '$'))
			parser->str = create_env(parser->str);
		parser = parser->next;
	}
}

void	ft_process(void)
{
	t_parser	*parser;
	char		**split;
	char		*str;

	while (1)
	{
		str = readline("bash$: ");
		if (ft_is_single_quote(str))
			ft_error();
		split = ft_create_split(str);
		parser = ft_createnodes(split);
		determine_type(parser);
		check_env(parser);
		remove_quo_pars(parser);
		ft_printlist(parser);
	}
}
