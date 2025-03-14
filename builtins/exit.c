/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 16:56:33 by fatturan          #+#    #+#             */
/*   Updated: 2024/02/24 15:52:46 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_exit_nbr(char *str)
{
	while (*str)
	{
		if ((ft_isdigit(*str)) || (*str == '+') || (*str == '-'))
			(*str)++;
		return (0);
	}
	return (1); 
}

//3 durum var sadece exit yazılması 2den fazla arg olması non-numeric olma durumu
void	ft_exit(t_command *cmd)
{
	if (ft_arg_count(cmd->exec) == 1)
	{
		printf("exit\n");
		exit(1);
	}
	else
	{
		if (ft_exit_nbr(cmd->exec->next->value))
		{
			if (ft_arg_count(cmd->exec) > 1)
			{
				write(2, "exit\n exit: too many arguments\n", 41);
				//errno = 1;
				return ;
			}
			printf("exit\n");
			exit(ft_atoi(cmd->exec->next->value) % 256);
		}
		write (2, "exit\n exit: numeric argument required\n", 39);
		exit(-1 % 256);
	}
}