/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 12:18:59 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:23:59 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		res++;
	while (n != 0)
	{
		res++;
		n /= 10;
	}
	return (res);
}

static long long	abs_n(int n)
{
	long long	res;

	res = 1;
	if (n < 0)
		res *= -(long long)n;
	else
		res = res * n;
	return (res);
}

char	*ft_itoa(int n)
{
	int			sign;
	int			i;
	char		*res;
	long long	nbr;

	nbr = abs_n(n);
	i = ft_len(n);
	sign = 0;
	if (n < 0)
		sign = 1;
	res = malloc(ft_len(n) + 1);
	if (!res)
		return (NULL);
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i--] = '0' + nbr % 10;
		nbr = nbr / 10;
	}
	if (sign == 1)
		res[0] = '-';
	return (res);
}
/*
int main() {
    // Test cases with positive integers
    int test_cases[] = {0, 1, 123, 987654, 1000, 999999, 2147483647}; // INT_MAX
    int num_cases = sizeof(test_cases) / sizeof(test_cases[0]);

    printf("Positive integers:\n");
    for (int i = 0; i < num_cases; i++) {
        int num = test_cases[i];
        char *result = ft_itoa(num);
        printf("%d -> %s\n", num, result);
        free(result); // Free dynamically allocated memory
    }

    // Test cases with negative integers
    int test_cases_negative[] = {-1, -123, -987654, -1000, -999999, -2147483647};
    int num_cases_negative = sizeof(test_cases_negative) 
    / sizeof(test_cases_negative[0]);

    printf("\nNegative integers:\n");
    for (int i = 0; i < num_cases_negative; i++) {
        int num = test_cases_negative[i];
        char *result = ft_itoa(num);
        printf("%d -> %s\n", num, result);
        free(result); // Free dynamically allocated memory
    }

    // Edge case: INT_MIN
    printf("\nEdge case: INT_MIN\n");
    int edge_case = -2147483648; // INT_MIN
    char *result_edge = ft_itoa(edge_case);
    printf("%d -> %s\n", edge_case, result_edge);
    free(result_edge); // Free dynamically allocated memory

    return 0;
}*/