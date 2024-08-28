/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 18:20:32 by oshcheho          #+#    #+#             */
/*   Updated: 2024/04/18 13:22:23 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}
/*
int main() {
    // Test case: positive number
    const char *str1 = "0";
    printf("String: \"%s\", Converted Value: %d\n", str1, ft_atoi(str1));

    // Test case: negative number
    const char *str2 = "-456";
    printf("String: \"%s\", Converted Value: %d\n", str2, ft_atoi(str2));

    // Test case: leading whitespace
    const char *str3 = "   789";
    printf("String: \"%s\", Converted Value: %d\n", str3, ft_atoi(str3));

    // Test case: trailing characters after number
    const char *str4 = "987xyz";
    printf("String: \"%s\", Converted Value: %d\n", str4, ft_atoi(str4));

    // Test case: empty string
    const char *str5 = "";
    printf("String: \"%s\", Converted Value: %d\n", str5, ft_atoi(str5));

    return 0;
}*/