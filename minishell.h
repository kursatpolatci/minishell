/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:24:13 by kpolatci          #+#    #+#             */
/*   Updated: 2023/12/24 07:08:16 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <readline/readline.h>
# include <string.h>
enum e_token
{
	ARG,
	INPUT_R,
	OUTPUT_R,
	D_INPUT_R,
	D_OUTPUT_R,
	PIPE,
};

typedef struct s_parser
{
	struct s_parser	*next;
	enum e_token	type;
	char			*str;
}				t_parser;

// linked_list_utils
t_parser	*ft_nodelast(t_parser	*pars);
void		ft_nodeadd_back(t_parser **pars, t_parser *new);
t_parser	*ft_nodenew(char *str);
t_parser	*ft_createnodes(char **str);
int			ft_arg_count(t_parser *main);

// parser
int			ft_is_single_quote(char *str);
char		*ft_substr(char *str, int start, int end);
char		**ft_create_split(char *str);
void		ft_process(void);

// temp	
void		ft_print_split(char **str);
void		ft_printlist(t_parser *parser);
void		ft_error(void);

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
int			ft_strlen_split(char **str);
void		ft_strlcpy(char *src, char *dst, int size);
char		*ft_strdup(char *str);
int			ft_find_char(char *str, char c);

// utils4
void		remove_quo_pars(t_parser *pars);
char		*ft_removed(char *str);
int			ft_count_for_rem(char *str);
void		determine_type(t_parser *pars);

// builtins
void		ft_echo(t_parser *main);
void		ft_pwd(void);
void		ft_exit(t_parser *main);

// env
char		*create_env(char *node_str);
void		copy_env(char *src, char *dest, int *dest_i, int *src_i);
void		copy_env_single_quo(char *src, char *dest, int *dest_i, int *src_i);
void		copy_env_double_quo(char *src, char *dest, int *dest_i, int *src_i);
void		copy_env_dollar(char *src, char *dest, int *dest_i, int *src_i);

// env utils1
int			count_for_env(char *str);
void		count_dollar(char *str, int *index, int *len);
void		count_for_single_quo(char *str, char c, int *index, int *len);
void		count_for_double_quo(char *str, char c, int *index, int *len);

// env utils2
int			is_special_char(char c);
char		*dollar_substr(char *str, int index);
char		*dollar_value(char *dol_sub, char **t_glb);

#endif