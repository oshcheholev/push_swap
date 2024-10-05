/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 16:45:12 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/04 12:37:44 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_arrs(t_ps *ps)
{
	int	i;

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

void	err_exit(t_ps *ps, char *msg)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	(void)msg;
	clean_arrs(ps);
	exit (1);
}

void	check_char(t_ps *ps, char *nptr)
{
	int	i;

	i = 0;
	if (nptr[0] == '\0')
		err_exit(ps, "empty");
	if (nptr[0] == ' ')
		if (nptr[1] == ' ' || nptr[1] == '\0')
			err_exit(ps, "ch1");
	while (nptr[i] != '\0')
	{
		if ((nptr[i] < '0' || nptr[i] > '9') && nptr[i] != '-'
			&& nptr[i] != '+' && nptr[i] != ' ')
			err_exit(ps, "atoi1");
		if ((nptr[i] >= '0' && nptr[i] <= '9') && (nptr[i + 1] == '-'
				|| nptr[i + 1] == '+'))
			err_exit(ps, "atoi2");
		if ((nptr[i + 1] < '0' || nptr[i + 1] > '9') && (nptr[i] == '-'
				|| nptr[i] == '+'))
			err_exit(ps, "atoi3");
		i++;
	}
}

void	check_dup(t_ps *ps)
{
	int	i;
	int	j;

	i = 0;
	while (i < ps->a_len - 1)
	{
		j = i + 1;
		while (j < ps->a_len)
		{
			if (ps->stack_a[i].value == ps->stack_a[j].value)
				err_exit(ps, "d1");
			j++;
		}
		i++;
	}
}

void	check_if_sorted(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->a_len - 1)
	{
		if (ps->stack_a[i].value > ps->stack_a[i + 1].value)
			return ;
		i++;
	}
	clean_arrs(ps);
	exit (0);
}
