/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 22:24:13 by kpolatci          #+#    #+#             */
/*   Updated: 2023/12/23 08:10:47 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv)
{
	char	**g_env;

	g_env = (char **)malloc(sizeof(char *) * 4);
	g_env[0] = "HOME=/home/kpolatci";
	g_env[1] = "USER=kpolatci";
	g_env[2] = "TERM_PROGRAM=vscode";
	g_env[3] = 0;
	//printf("%d\n", count_for_env("merhaba\'$USER\'.asd$USER.ASD\"mer$USER.asd\".asd$USERR"));
	//printf("%d\n", count_for_env("merhaba\'$USER\'.asd$USER.ASD\"mer$USER.asd\".asd$USERR."));
	//printf("%d\n", count_for_env("merhaba\'$USER\'.asd$USER.ASD\"mer$USER.asd\".asd"));
	//printf("%d\n", count_for_env("merhaba\'$USER\'.asd$USER.ASD\"mer$USER.asd\".asd$"));
	//printf("count: %d\n", count_for_env("$"));
	//printf("count: %d\n", count_for_env("\'$\'"));
	//printf("count: %d\n", count_for_env("\"$.asd\""));
	//printf("count: %d\n", count_for_env("\"$ .asd\""));
	//printf("count: %d\n", count_for_env("\"$u.asd\""));
	//printf("count: %d\n", count_for_env("$a"));
	//printf("count: %d\n", count_for_env("$ "));
	
	
	//printf("%s\n", create_env("\'naber\'"));
	//printf("%s\n", create_env("\'$asd.naber\'"));
	//printf("%s\n", create_env("\"$asd.naber\""));
	//printf("%s\n", create_env("\"$USER.naber\""));
	//printf("%s\n", create_env("\"$USERr.naber\""));
	//printf("%s\n", create_env("\"$USERr.naber\'$USER\'\""));
	//printf("%s\n", create_env("\"$USERr.naber\'$USER\'\""));
	printf("%s\n", create_env("$USER"));
	printf("%s\n", create_env("$USER$HOME"));
	//ft_process(); 
}
