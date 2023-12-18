/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:50:28 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:50:28 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
		while (*s != '\0')
			ft_putchar_fd(*s++, fd);
	ft_putchar_fd('\n', fd);
}

/*
#include <fcntl.h>
int main() {
	int fd = open("putendl.txt", O_CREAT | O_RDWR, 0777);
	ft_putendl_fd("Kursat", fd);
	ft_putendl_fd("Polatci", fd);
}*/