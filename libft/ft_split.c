/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 10:57:06 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 15:00:16 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	arr_size(char const *s, char c)
{
	long long int	i;
	long long int	j;
	long long int	res;

	i = 0;
	j = 0;
	res = 0;
	while (*(s + i))
	{
		if (!(*(char *)(s + i) == c) && j == 0)
		{
			res++;
			j++;
		}
		else if (*(char *)(s + i) == c)
			j = 0;
		i++;
	}
	return (res);
}

static void	free_arr(size_t i, char **arr)
{
	while (i)
	{
		i--;
		free(*(arr + i));
	}
	free(arr);
}

static char	*fill_line(char const *s, long long int len, char c)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (free(res), NULL);
	while ((*(s + i)) && !(*(s + i) == c))
	{
		*(res + i) = *(s + i);
		i++;
	}
	*(res + i) = '\0';
	return (res);
}

static char	**split(char const *s, char **arr, char c, size_t arr_len)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (i < arr_len)
	{
		while (*s == c)
			s++;
		word_len = 0;
		while (*(char *)(s + word_len) && !(*(char *)(s + word_len) == c))
			word_len++;
		arr[i] = fill_line(s, word_len, c);
		if (!arr[i])
		{
			free_arr(i, arr);
			return (NULL);
		}
		i++;
		s += word_len;
	}
	arr[arr_len] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		arr_len;

	arr_len = arr_size(s, c);
	arr = malloc((arr_len + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	return (split(s, arr, c, arr_len));
}
/*
int main()
{
     char *s = "ababc";
    char **split_result = ft_split(s, 'b');

    if (split_result)
    {
        // Print each substring
        printf("Split Result:\n");
        for (int i = 0; split_result[i] != NULL; i++)
        {
            printf("%s\n", split_result[i]);
            free(split_result[i]); // Free each substring
        }
        free(split_result); // Free the array of strings
    }
    else
    {
        printf("Failed to split the string.\n");
        return 1; // Return an error code to indicate failure
    }

    return 0;
}*/