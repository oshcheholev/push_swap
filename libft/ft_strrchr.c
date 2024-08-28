/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:11:37 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:48:53 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*temp;

	i = 0;
	temp = NULL;
	while (s[i] != '\0')
		i++;
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	while (i > 0)
	{
		if ((unsigned char)s[i - 1] == (unsigned char)c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return ((char *)temp);
}
/*
int main() {
    const char *str = "teste";
    int search_char = 'e';  // Character to search for

    // Call ft_strrchr function
    char *result = ft_strrchr(str, search_char);

    // Print the result
    if (result != NULL) {
        printf("Last'%c' in \"%s\" at %ld\n", search_char, str, result - str);
    } else {
        printf("'%c' not found in \"%s\"\n", search_char, str);
    }

    return 0;
}*/
