/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 13:12:37 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:48:13 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

static size_t	inset(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*empty_str(void)
{
	char	*res;

	res = malloc(1 * sizeof(char));
	if (!res)
		return (NULL);
	res[0] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	size_t	end;
	char	*res;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	end = strlen(s1);
	while (i < strlen(s1) && inset(set, s1[i]))
		i++;
	if (i == end)
		return (empty_str());
	while (inset(set, s1[end - 1]))
		end--;
	res = malloc(((end - i) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (i < end)
	{
		res[j++] = s1[i++];
	}
	res[j] = '\0';
	return (res);
}
/*
int main() {
    const char *s1 = "  \t  Hello, world!  \t  ";
    const char *set = " \t";

    printf("Original string: \"%s\"\n", s1);

    char *trimmed = ft_strtrim(s1, set);
    if (trimmed) {
        printf("Trimmed string: \"%s\"\n", trimmed);
        free(trimmed);
    } else {
        printf("Trimmed string is NULL\n");
    }

    return 0;
}*/
