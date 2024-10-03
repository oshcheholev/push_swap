/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:46:17 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 17:13:37 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi_new(char *nptr, t_ps *ps)
{
	static int	i = 0;
	int			sign;
	long int	res;

	res = 0;
	sign = 1;
	i = 0;
	check_char(ps, nptr);
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
		if (sign == -1 && res > 2147483648)
			err_exit(ps, "atoi6");
		i++;
	}
	return (res * sign);
}

int	check_input(char *str, t_ps *ps)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
			&& str[i] != '+')
		{
			if (str[i] == ' ')
			{
				if (str[i + 1] != ' ' && str[i + 1] != '\0')
					word_count++;
			}
			else
				err_exit(ps, "ch2");
		}
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] < '0' || str[i + 1] > '9'))
			err_exit(ps, "c3");
		i++;
	}
	return (word_count + 1);
}

void	process_input(t_ps *ps, char *str)
{
	int	i;

	i = 0;
	ps->a_len = check_input(str, ps);
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

void	sort_small(t_ps *ps)
{
	if (ps->a_len == 1)
		return ;
	if (ps->a_len == 2)
	{
		if (ps->stack_a[0].value > ps->stack_a[1].value)
			sa(ps);
	}
	if (ps->a_len == 3)
		sort_3(ps);
	if (ps->a_len == 4)
		sort_4(ps);
	if (ps->a_len == 5)
		sort_5(ps);
	if (ps->a_len > 5)
	{
		first_move_to_b(ps);
		ps->first_move = 1;
		sort_5(ps);
		while (ps->b_len > 0)
			put_el_to_a(ps);
		restore_a(ps);
	}
}
