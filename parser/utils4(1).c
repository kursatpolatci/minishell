/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 15:47:15 by kpolatci          #+#    #+#             */
/*   Updated: 2024/02/24 15:51:59 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


int	ft_strlen_split(char **str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strcpy(char *src, char *dst, int size)
{
	int	index;

	index = 0;
	while (index < size)
	{
		dst[index] = src[index];
		index++;
	}
	dst[index] = '\0';
}

char	*ft_substring(char *str, int start, int end)
{
	char	*sub;
	int		index;

	index = 0;
	if (end >= ft_strlen(str))
		return (0);
	sub = (char *)malloc(sizeof(char) * end - start + 2);
	sub[end - start + 1] = '\0';
	while (start <= end)
		sub[index++] = str[start++];
	return (sub);
}

int	str_in_array(const char *s, char delimiter)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		if (*s == delimiter)
			s++;
		else
		{
			while (*s != delimiter && *s)
				s++;
			count++;
		}
	}
	return (count);
}

int	ft_arg_count(t_execute *exec)
{
	int	len;

	len = 0;
	if (exec->next == NULL)
		return (1);
	while (exec->next)
	{
		len++;
		exec = exec->next;
	}
	return (len);
}

//int	ft_strlen(char *str)
//{
//	int	len;

//	len = 0;
//	if (!str)
//		return (0);
//	while (str[len])
//		len++;
//	return (len);
//}

//char	*ft_strdup(char *str)
//{
//	char	*dup;

//	dup = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
//	if (!dup)
//		return (0);
//	ft_strcpy(str, dup, ft_strlen(str));
//	return (dup);
//}