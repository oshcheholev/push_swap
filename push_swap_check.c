/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:46:17 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/02 15:03:48 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void test_print(t_ps *ps)
{
	int i;
	
	i = 0;
	while (i < ps->a_len)
	{
		printf("AAAA i %d ,   stack[i] %d\n", i, ps->stack_a[i].value);
		i++;
	}
	printf("\n");
	
	i = 0;
	while (i < ps->b_len)
	{
		printf("BBBB i %d ,   stack[i] %d\n", i, ps->stack_b[i].value);
		i++;
	}
	printf("\n");
}

void clean_arrs(t_ps *ps)
{
	int i;
	
	i = 0;
	if (ps->stack_a)
	{
		free(ps->stack_a);
		ps->stack_a = NULL;
	}
	if (ps->stack_b)
	{
		free(ps->stack_b);
		ps->stack_b = NULL;
	}
	if (ps->array)
	{
		while (ps->array[i])
		{
			free(ps->array[i]);
			i++;
		}
		free(ps->array);
	}
}


void err_exit(t_ps *ps, char *msg)
{
	int i;

	i = 0;
	write(2, "Error\n", 6);
	printf("%s\n", msg);
	(void)msg;
	clean_arrs(ps);
	exit (1);
	
}

long int	ft_atoi_new(const char *nptr, t_ps *ps)
{
	int	i;
	int	sign;
	long int	res;

	i = 0;
	res = 0;
	sign = 1;
	
		// printf("nptr %s\n", nptr);

	while (i < (int)ft_strlen(nptr))
	{
		if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '-' && nptr[i] != '+')
			err_exit(ps, "atoi1");
		if ((nptr[i] >= '0' && nptr[i] <= '9') && (nptr[i + 1] == '-' || nptr[i + 1] == '+'))
			err_exit(ps, "atoi2");
		if ((nptr[i + 1] < '0' || nptr[i + 1] > '9') && (nptr[i] == '-' || nptr[i] == '+'))
			err_exit(ps, "atoi3");
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
		res = res * 10 + nptr[i] - '0';
		if (sign == 1 && res > 2147483647)
			err_exit(ps, "atoi5");
		if (sign == -1 && res < -2147483648)
			err_exit(ps, "atoi6");
//		printf("res %d\n", res);
		i++;
	}
	return (res * sign);
}

int	check_input(char *str, t_ps *ps)
{
	int i;
	int word_count;

	i = 0;
	if (str[i] == ' ')
		if (str[i + 1] == ' ' || str[i + 1] == '\0')
			err_exit(ps, "ch1");
	word_count = 0;
	while (str[i] != '\0')
	{
//	printf("wc i%ci  +%d+\n", str[i], str[i + 1]);
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-' && str[i] != '+')
		{
			if (str[i] == ' ')
			{
			 	//if (str[i + 1] == ' ')
//					err_exit(ps, "ch1");
			 	if (str[i + 1] != ' ' && str[i + 1] != '\0')
					word_count++;
				// 	i++;
				// else
			}
			else
				err_exit(ps, "ch2");
		}
		if ((str[i] == '-' || str[i] == '+') && (str[i + 1] < '0' || str[i + 1] > '9'))
			err_exit(ps, "c3");
		i++;
	}
//	printf("wc check  %d\n", word_count);
	return (word_count + 1);
}

void check_dup(t_ps *ps)
{
	int i;
	int j;
	
	i = 0;
	while (i < ps->a_len - 1)
	{
		j = i + 1;
//	printf("bbb %d  %d   %d\n", ps->a_len, ps->stack_a[i].value, ps->stack_a[j].value);
		while(j < ps->a_len)
		{
//	printf("bbb %d  %d   %d\n", ps->a_len, ps->stack_a[i].value, ps->stack_a[j].value);
			if (ps->stack_a[i].value == ps->stack_a[j].value)
				err_exit(ps, "d1");
			j++;
		}
		i++;
	}
}

void	process_input(t_ps *ps, char *str)
{
//	char **array;
	int i;

	i = 0;
	ps->a_len = check_input(str, ps);
	ps->stack_a = malloc(ps->a_len * sizeof(t_elem));
	if (!ps->stack_a)
		err_exit(ps, "pr1");
//printf("aaa %d\n", ps->a_len);
	ps->array = ft_split(str, ' ');
	if (!ps->array)
		return (free(ps->array), err_exit(ps, "split"));
	while (ps->array[i] != NULL)
	{
		if (ps->array[i][0] != '\0')
			ps->stack_a[i].value = ft_atoi_new(ps->array[i], ps);
//		printf("aaa %d\n", ps->stack_a[i].value);

//		if (!)free(array[i]);
		i++;
	}
	// i = 0;
	// while (array[i])
	// {
	// 	free(array[i]);
	// 	i++;
	// }
	// free(array);
}

void check_if_sorted(t_ps *ps)
{
	int i;
	
	i = 0;
	while (i < ps->a_len - 1)
	{
		if(ps->stack_a[i].value > ps->stack_a[i + 1].value)
			return ;
		i++;
	}
	clean_arrs(ps);
	exit (0);
}

void arr_or_not(t_ps *ps, int argc, char **argv)
{
	int i;
	i = 0;
	if (argc == 2)
		if(ft_strlen(argv[1]) == 0)
			err_exit(ps, "empty");
		else
			process_input(ps, argv[1]);
	else if (argc == 1)
		err_exit(ps, "arg");
//		exit(0);
	else
	{
		ps->stack_a = malloc(argc * sizeof(t_elem));
		if (!ps->stack_a)
			err_exit(ps, "m");
		while (argv[i + 1])
		{
			ps->stack_a[i].value = ft_atoi_new(argv[i + 1], ps);
			i++;
		}
	}
	i = 0;
//	printf("sss %d \n", ps->a_len);
//	test_print(ps);
	check_dup(ps);
	check_if_sorted(ps);
}
