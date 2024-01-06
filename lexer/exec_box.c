/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatturan <fa.betulturan@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 19:07:26 by fatturan          #+#    #+#             */
/*   Updated: 2024/01/05 22:21:45 by fatturan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_prev_type(enum e_token type)
{
	if (type == D_INPUT_R || type == D_OUTPUT_R || type == OUTPUT_R || type == INPUT_R)
		return (1);
	return (0);
}

t_execute	*ft_last_exec(t_execute *exec)
{
	if (exec)
	{
		while (exec->next)
			exec = exec->next;
		return (exec);
	}
	return (0);
}

void	ft_add_exec_box(t_execute **exec, t_execute *new_exec)
{
	t_execute *temp;

	if (exec)
	{
		if (*exec == NULL)
			*exec = new_exec;
		else
		{
			temp = ft_last_exec(*exec);
			temp->next = new_exec;
		}
	}
		
}

t_execute	*ft_init_exec_box(char *str)
{
	t_execute *new_exec;

	new_exec = malloc(sizeof(t_execute));
	new_exec->value = str;
	new_exec->next = NULL;
	return(new_exec);
}

t_execute	*ft_exec_box(t_execute **exec, t_parser *main)
{
	t_execute *new_exec;

	if(main->type == ARG && main->str[0])
	{
		new_exec = ft_init_exec_box(main->str);
		ft_add_exec_box(exec, new_exec);
	}
	else if(main->type == ARG && (check_prev_type()))
	{
		new_exec = ft_init_exec_box(main->str);
		ft_add_exec_box(exec, new_exec);	
	}
	return(*exec);
}
