/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 14:42:12 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:29:09 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ch;
	size_t			i;

	i = 0;
	ch = s;
	while (i < n)
	{
		ch[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main(void) {
    char str[20] = "Hello, world!";
    printf("Before memset: %s\n", str);
    ft_memset(str, '*', 5);
    printf("After memset: %s\n", str);
    return 0;
}*/
