/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:46:17 by oshcheho          #+#    #+#             */
/*   Updated: 2024/08/28 14:53:08 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_print(t_ps *ps)
{
	int i;
	
	i = 0;
	while (i < ps->a_len)
	{
		printf("AAAA i %d ,   stack[i] %d\n", i, ps->stack_a[i]);
		i++;
	}
	printf("\n");
	
	i = 0;
	while (i < ps->b_len)
	{
		printf("BBBB i %d ,   stack[i] %d\n", i, ps->stack_b[i]);
		i++;
	}
	printf("\n");
}

void err_exit(t_ps *ps)
{
	int i;

	i = 0;
	write(1, "Error\n", 6);
	
	if (ps->stack_a)
	{
		free(ps->stack_a);
	}
	if (ps->stack_b)
	{
		free(ps->stack_b);
	}
	exit (1);
	
}

int	ft_atoi_new(const char *nptr, t_ps *ps)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	res = 0;
	sign = 1;
	
		// printf("nptr %s\n", nptr);

	while (i < (int)ft_strlen(nptr))
	{
		if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '-' && nptr[i] != '+')
			err_exit(ps);
		if ((nptr[i] >= '0' && nptr[i] <= '9') && (nptr[i + 1] == '-' || nptr[i + 1] == '+'))
			err_exit(ps);
		if ((nptr[i + 1] < '0' || nptr[i + 1] > '9') && (nptr[i] == '-' || nptr[i] == '+'))
			err_exit(ps);
		i++;
	}
	i = 0;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (sign == 1 && res > (INT_MAX - (nptr[i] - '0')) / 10)
			err_exit(ps);
		if (sign == -1 && res > (-(INT_MIN + (nptr[i] - '0')) / 10))
			err_exit(ps);
//		printf("res %d\n", res);
		res = res * 10 + nptr[i] - '0';
		i++;
	}
	return (res * sign);
}

int	check_input(char *str, t_ps *ps)
{
	int i;
	int word_count;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		{
			if (str[i] == ' ')
				if (str[i + 1] == ' ' || str[i + 1] == '\0')
					err_exit(ps);
				else
					word_count++;
			else
				err_exit(ps);
		}
		if ((str[i] == '-' || str[i] == '-') && (str[i + 1] < '0' || str[i + 1] > '9'))
			err_exit(ps);
		i++;
	}
	printf("wc check  %d\n", word_count);
	return (word_count + 1);
}

void check_dup(int *stack, t_ps *ps)
{
	int i;
	int j;
	
	i = 0;
	while (i < ps->a_len - 1)
	{
		j = i + 1;
		while(j < ps->a_len)
		{
			if (stack[i] == stack[j])
				err_exit(ps);
			j++;
		}
		i++;
	}
}

void	process_input(t_ps *ps, char *str)
{
	char **array;
	int i;

	i = 0;
	ps->a_len = check_input(str, ps);
	ps->stack_a = malloc(ps->a_len * sizeof(int));
	if (!ps->stack_a)
		err_exit(ps);
	array = ft_split(str, ' ');
	if (!array)
		return (free(array));
	while (array[i] != NULL)
	{
		ps->stack_a[i] = ft_atoi_new(array[i], ps);
		i++;
	}
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void arr_or_not(t_ps *ps, int argc, char **argv)
{
	int i;
	
	i = 0;
	if (argc == 2)
		process_input(ps, argv[1]);
	else if (argc == 1)
		err_exit(ps);
	else
	{
		ps->stack_a = malloc(argc * sizeof(int));
		if (!ps->stack_a)
			err_exit(ps);
		while (argv[i + 1])
		{
			ps->stack_a[i] = ft_atoi_new(argv[i + 1], ps);
			i++;
		}
	}
	test_print(ps);
	check_dup(ps->stack_a, ps);
}
