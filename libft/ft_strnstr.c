/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 17:28:00 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:48:48 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = 0;
	res = NULL;
	if (small[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		if (big[i] == small[j])
		{
			res = (char *)&big[i];
			while (small[j] != '\0' && big[i + j] == small[j]
				&& (i + j) < len)
				j++;
			if (small[j] == '\0')
				return (res);
		}
		res = NULL;
		i++;
	}
	return (res);
}
/*
int main() {
    const char *big = "Hello, World!";
    const char *small = "";
    size_t len = 13; // Length of "Hello, World!"

    char *result = ft_strnstr(big, small, len);

    if (result != NULL) {
        printf("Substr '%s' found pos %s str: %s\n", small, result, big);
    } else {
        printf("Substring '%s' not found in the string: %s\n", small, big);
    }

    return 0;
}
*/
