/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:24:13 by kpolatci          #+#    #+#             */
/*   Updated: 2023/10/25 22:15:46 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>

enum e_token
{
	COMMAND = 1,
	ARGUMENT = 2
	asdasd
	asd
	asdasd
	asd
};

typedef struct s_parser
{
	struct s_parser	*next;
	char			*str;
	int				value;
}	t_parser;

// linked_list_utils1
t_parser	*ft_nodelast(t_parser	*pars);
void		ft_nodeadd_back(t_parser **pars, t_parser *new);
t_parser	*ft_nodenew(char *str);
t_parser	*ft_createnodes(char **str);
void		ft_printlist(t_parser *parser);

// parser
int			ft_is_single_quote(char *str);
char		*ft_substring(char *str, int start, int end);
char		**ft_create_split(char *str);
void		ft_process(void);

// utils1
void		pass_whitespaces(char *str, int *index);
void		pass_quotes(char *str, int *index, char c);
void		pass_redirection(char *str, int *index, int *count);
void		pass_word(char *str, int *index, int *count);
int			ft_argc_count(char *str);

// utils2
int			ft_is_whitespaces(char c);
int			ft_is_quotes(char c);
int			ft_is_redirection(char c);
int			ft_find_str(char *str, char *c, int *index);

// utils3
int			ft_strlen(char *str);
void		ft_strlcpy(char *src, char *dst, int size);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *str);

// temp	
void		ft_print_split(char **str);
void		ft_error(void);

#endif