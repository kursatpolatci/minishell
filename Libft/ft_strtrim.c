/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:04:10 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 17:04:10 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		index;
	char	*ret;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	while (s1[start] != '\0' && ft_strchr(set, s1[start]))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (end > 0 && ft_strchr(set, s1[end - 1]))
		end--;
	ret = malloc(sizeof(char) * (end - start + 1));
	if (!ret)
		return (NULL);
	index = 0;
	while (start < end)
	{
		ret[index++] = s1[start++];
	}
	ret[index] = '\0';
	return (ret);
}

/*
#include <stdio.h>
int	main(void)
{
	char	*trim = "xXax Kuvarti xXx";
	char	*set = "xX ";

	printf("%s\n", ft_strtrim(trim, set));

	char	*trim2 = " xXax Kuvarti xXx ";
	char	*set2 = " xaX";

	printf("%s\n", ft_strtrim(trim2, set2));

	char	*trim3 = "xXax Kuvarti xXx";
	char	*set3 = "xXia ";

	printf("%s\n", ft_strtrim(trim3, set3));
}*/