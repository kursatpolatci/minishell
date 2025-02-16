/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:24:13 by kpolatci          #+#    #+#             */
/*   Updated: 2024/02/27 18:17:45 by kpolatci         ###   ########.fr       */
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
# include <fcntl.h>
# include <dirent.h>
# include "./Libft/libft.h"

enum e_token
{
	ARG,
	INPUT_R,
	OUTPUT_R,
	D_INPUT_R,
	D_OUTPUT_R,
	PIPE,
	IN_FILE,
	OUT_FILE,
	D_IN_FILE,
	D_OUT_FILE,
	NONE,
};

typedef struct s_execute
{
	char				*value;
	struct s_execute	*next;
	struct s_execute 	*prev;
}				t_execute;

typedef struct s_redirect
{
	char 				*value;
	enum e_token		type;
	struct	s_redirect 	*next;
	struct	s_redirect 	*prev;
}				t_redirect;

typedef struct s_command
{
	int					fd[2];
	int					heredoc_fd[2];
	t_execute			*exec;
	t_redirect			*redirect;
	struct s_command	*next;
	struct s_command 	*prev;
	pid_t				p_pid;
}				t_command;

typedef struct s_parser
{
	struct s_parser	*next;
	struct s_parser	*prev;
	enum e_token	type;
	char			*str;
}				t_parser;

typedef struct s_glbl
{
	char				**env;
	char				**export;
	char				**path;
	char				*input;
	t_command			*cmd;
	int					exp_plus_flag;
	int					cmd_count;
	int					fd[2];
	int					heredoc;
	int					erorno;
}						t_glbl;

t_glbl		g_glbl;

////////////////////////// BUILTINS //////////////////////////

// cd
void		ft_export_pwd(char *old_pwd, char *new_pwd);
void		ft_env_pwd(char *old_pwd, char *new_pwd);
void		ft_cd_error(char *s1, char *s2);
void		ft_cd_two(t_command *cmd);
void		ft_cd(t_command *cmd);

// echo
t_execute	*ft_check_n(t_execute *exec, int *flag);
void		ft_echo(t_command *cmd);

// env
void		ft_env(t_execute *exec);

// exit
int			ft_exit_nbr(char *str);
void		ft_exit(t_command *cmd);

// export
int			ft_sub_equal(char *s1, char *s2, int *i, int *j);
int			ft_is_equal(char *s1, char *s2);
int			ft_if_equal(char **new, int *i, char *value, char *flag);
void		ft_add_exp(char **new_exp, char *value);
void		ft_add_env(char **new_env, char *value);
int			ft_exp_count(void);
void		ft_add_to(char *value, char *flag);
void		ft_env_or_exp(t_execute *exec);
int			ft_check_err(char *value, char *flag);
int			ft_exec_count(t_execute *exec);
void		ft_print_export(void);
void		ft_export(t_command *command);

// pwd
void		ft_pwd(void);

// unset
int			ft_strncmp1(char *tmp, char *value, int len);
char		*ft_before_equal(char *str);
void		ft_del_exp(char *del);
void		ft_del_env(char *del);
void		ft_unset(t_command *cmd);

////////////////////////// ENV //////////////////////////

// env_utils1
int			count_for_env(char *str);
void		count_dollar(char *str, int *index, int *len);
void		count_for_single_quo(char *str, char c, int *index, int *len);
void		count_for_double_quo(char *str, char c, int *index, int *len);

// env_utils2
int			is_special_char(char c);
char		*dollar_substr(char *str, int index);
char		*dollar_value(char *dol_sub, char **t_glb);

// env
char		*create_env(char *node_str);
void		copy_env(char *src, char *dest, int *dest_i, int *src_i);
void		copy_env_single_quo(char *src, char *dest, int *dest_i, int *src_i);
void		copy_env_double_quo(char *src, char *dest, int *dest_i, int *src_i);
void		copy_env_dollar(char *src, char *dest, int *dest_i, int *src_i);

////////////////////////// EXECUTE //////////////////////////

// action
char		**ft_args_fill(t_execute *execute);
int			ft_redi_outputs(t_command *cmd);
void		ft_pipe_route(t_command *cmd);
void		ft_command_route(t_command *cmd);
void		ft_action(t_command *cmd);

// close_fd
void		ft_close_all_fd(void);
void		directory_err(char *str);

// create_file
int			ft_output(char *file, int mode);
int			ft_input(char *file);

// fill_path
char		*ft_split_path(char *env_path);
char		*ft_env_path(char *path);
void		ft_fill_path(void);

// get_path
void		ft_no_file_err(char *cmd);
void		ft_command_err(char *cmd);
void		ft_check_dir(char *command);
char		*ft_getpath(char *cmd);


//heredoc

int			ft_is_heredoc(void);
void		ft_heredoc_route(t_command *cmd);
int			ft_closing_words(char *str1, char *str2);
void		ft_get_heredoc(char *endline, int *fd);
void		heredoc(int *fd, char *endline);


// run_builtins
//void		ft_wait_cmd(void);
int			ft_process_builtins(t_command *cmd);
void		ft_run_builtins(t_command *cmd);
int			ft_is_builtin(t_command *cmd);
void		ft_process_cmd(void);

////////////////////////// LEXER //////////////////////////

// boxing
void		ft_send_box(t_command *cmd, t_parser **main);
void		ft_add_box(t_command *cmd);
t_command	*ft_init_cmd(void);
void		ft_cmd_box(t_parser *main);

// exec_box
int			check_prev_type(enum e_token type);
t_execute	*ft_last_exec(t_execute *exec);
void		ft_add_exec_box(t_execute **exec, t_execute *new_exec);
t_execute	*ft_init_exec_box(char *str);
t_execute	*ft_exec_box(t_execute **exec, t_parser *main);

// redirect_box
t_redirect	*ft_last_redirect(t_redirect *redirect);
void		ft_add_redirect_box(t_redirect **redirect, t_redirect *new);
t_redirect	*ft_init_redirect_box(enum e_token type, char *str);
t_redirect	*ft_redirect_box(t_redirect **redirect, t_parser *main);

////////////////////////// PARSER //////////////////////////

// linked_list_utils
t_parser	*ft_nodelast(t_parser	*pars);
void		ft_nodeadd_back(t_parser **pars, t_parser *new);
t_parser	*ft_nodenew(char *str);
t_parser	*ft_createnodes(char **str);
void		ft_add_prev_parser(t_parser	*parser);

// parser
int			ft_is_single_quote(char *str);
char		**ft_create_split(char *str);
void		check_env(t_parser *parser);
void		init_envair(char **env);
void		ft_process(void);

// temp	
void		ft_print_split(char **str);
void		ft_printlist(t_parser *parser);
void		ft_error(void);
void		ft_free_split(char **str);
void 		ft_print_cmd();

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
int			ft_find_char(char *str, char c);

// utils3
void		remove_quo_pars(t_parser *pars);
char		*ft_removed(char *str);
int			ft_count_for_rem(char *str);
void		determine_type(t_parser *pars);
void		last_is_pipe(t_parser *pars);

// utils4
int			ft_strlen_split(char **str);
void		ft_strcpy(char *src, char *dst, int size);
char		*ft_substring(char *str, int start, int end);
int			str_in_array(const char *s, char delimiter);
int			ft_arg_count(t_execute *exec);

#endif