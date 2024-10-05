/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:46:17 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/04 15:12:42 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_new(char *nptr, t_ps *ps)
{
	int			i;
	int			sign;
	long int	res;

	res = 0;
	sign = 1;
	i = 0;
	check_char(ps, nptr);
	if (nptr[i] == '-')
		sign = -1;
	if (nptr[i] == '+' || nptr[i] == '-')
		i++;
	while (nptr[i] != '\0')
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			err_exit(ps, "char err");
		res = res * 10 + nptr[i] - '0';
		if (sign == 1 && res > 2147483647)
			err_exit(ps, "atoi5");
		if (sign == -1 && res > 2147483648)
			err_exit(ps, "atoi6");
		i++;
	}
	return (res * sign);
}

int	count_words(char *str, t_ps *ps)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	if (str[0] == ' ')
		err_exit(ps, "space");
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
		{
			if ((str[i + 1] >= '0' && str[i + 1] <= '9')
				|| str[i + 1] == '\0' || str[i + 1] == '-'
				|| str[i + 1] == '+')
				word_count++;
		}
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] < '0' || str[i + 1] > '9'))
			err_exit(ps, "c3");
		i++;
	}
	return (word_count + 1);
}

void	check_input(char *str, t_ps *ps)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
			&& str[i] != '+')
		{
			if (str[i] == ' ')
			{
				if ((str[i + 1] < '0' || str[i + 1] > '9')
					&& str[i + 1] != '-' && str[i + 1] != '+')
					err_exit(ps, "char");
			}
			else
				err_exit(ps, "char2");
		}
		i++;
	}
}

void	process_input(t_ps *ps, char *str)
{
	int	i;

	i = 0;
	check_input(str, ps);
	ps->a_len = count_words(str, ps);
	ps->stack_a = malloc(ps->a_len * sizeof(t_elem));
	if (!ps->stack_a)
		err_exit(ps, "pr1");
	ps->array = ft_split(str, ' ');
	if (!ps->array)
		return (free(ps->array), err_exit(ps, "split"));
	while (ps->array[i] != NULL)
	{
		if (ps->array[i][0] != '\0')
			ps->stack_a[i].value = ft_atoi_new(ps->array[i], ps);
		i++;
	}
}

void	arr_or_not(t_ps *ps, int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		check_char(ps, argv[1]);
		process_input(ps, argv[1]);
	}
	else if (argc == 1)
		exit(0);
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
	check_dup(ps);
	check_if_sorted(ps);
}
