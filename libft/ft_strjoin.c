/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 11:28:59 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:43:30 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen(char const *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	res = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	while (s2 && s2[j] != '\0')
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	return (res);
}
/*
int main() {
    // Test cases with non-NULL strings
    const char *s1 = "Hello, ";
    const char *s2 = "world!";
    char *result = ft_strjoin(s1, s2);
    printf("Concatenated string: %s\n", result);
    free(result);

    // Test case with s1 = NULL
    result = ft_strjoin(NULL, s2);
    printf("Concatenated string: %s\n", result);
    free(result);

    // Test case with s2 = NULL
    result = ft_strjoin(s1, NULL);
    printf("Concatenated string: %s\n", result);
    free(result);

    // Test case with both s1 and s2 = NULL
    result = ft_strjoin(NULL, NULL);
    if (!result) {
        printf("Both strings are NULL\n");
    } else {
        printf("Concatenated string: %s\n", result);
        free(result);
    }

    return 0;
}*/