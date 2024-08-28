/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:20:17 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:43:37 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_length(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = ft_length(dest);
	j = 0;
	destlen = ft_length(dest);
	srclen = ft_length(src);
	if (size == 0 || size <= destlen)
		return (srclen + size);
	while (src[j] != '\0' && j < size - destlen - 1)
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}
/*
int main() {
    char dst[20] = "Hello, ";
    const char *src = "World!";

    size_t len = ft_strlcat(dst, src, sizeof(dst));

    printf("Concatenated string: %s\n", dst);
    printf("Length of concatenated string: %zu\n", len);

    return 0;
}*/
