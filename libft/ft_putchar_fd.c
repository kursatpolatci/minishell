/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpolatci <kpolatci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:50:11 by kpolatci          #+#    #+#             */
/*   Updated: 2023/07/11 16:50:11 by kpolatci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
open: Bu işlev, bir dosyayı açmak veya oluşturmak için kullanılır. Header dosyası <fcntl.h> içeriği eklenmelidir.

"a.txt": Dosyanın adı veya yolunu belirtir. Bu örnekte, a.txt olarak adlandırılan bir dosya oluşturulacak veya mevcut olan açılacak.

O_CREAT: Bu bayrak, dosyanın oluşturulmasını sağlar. Eğer belirtilen dosya zaten varsa, bu bayrak göz ardı edilir. Yani, a.txt dosyası zaten varsa sadece açılır, yoksa oluşturulur.

O_RDWR: Bu bayrak, dosyanın hem okunabilir hem de yazılabilir olarak açılmasını sağlar. Bu, dosyayı okumak ve yazmak için kullanılacağını gösterir.

0777: Bu, oluşturulan dosyanın izinlerini belirtir. Octal formatta belirtilmiştir. 0777, dosyanın okunabilir, yazılabilir ve çalıştırılabilir olduğunu ifade eder. Bu, herkesin dosyayı okumasına, yazmasına ve çalıştırmasına izin verir.

fd: Bu değişken, open işlevinin dönüş değerini tutar. Eğer open işlevi başarılı olursa, dosyanın dosya tanımlayıcısını (file descriptor) döndürür. Eğer bir hata oluşursa, -1 değerini döndürür.
*/

/*
#include <fcntl.h>
int main() {
	int fd = open("a.txt", O_CREAT | O_RDWR, 0777);
	ft_putchar_fd('k', fd);
}*/