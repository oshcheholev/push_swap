/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:15:16 by oshcheho          #+#    #+#             */
/*   Updated: 2024/09/27 16:17:31 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_ps *ps)
{
	if (ps->stack_a[0].place == ps->middle - 1)
	{
		if (ps->stack_a[1].place == ps->middle)
			return ;
		else
		{
			rra(ps);
			sa(ps);
		}
	}
	else if (ps->stack_a[0].place == ps->middle)
	{
		if (ps->stack_a[1].place == ps->middle + 1)
			rra(ps);
		else
			sa(ps);
	}
	else if (ps->stack_a[0].place == ps->middle + 1)
	{
		if (ps->stack_a[1].place == ps->middle - 1)
			ra(ps);
		else
		{
			sa(ps);
			rra(ps);
		}
	}
}

int find_min(t_ps *ps)
{
	int i;
	int res;

	i = 0;
	res = ps->stack_a[0].place;
	while (i < ps->a_len)
	{
		if (ps->stack_a[i].place < res)
			res = ps->stack_a[i].place;
		i++;
	}
	return (res);
}

int find_max(t_ps *ps)
{
	int i;
	int res;

	i = 0;
	res = ps->stack_a[0].place;
	while (i < ps->a_len)
	{
		if (ps->stack_a[i].place > res)
			res = ps->stack_a[i].place;
		i++;
	}
	return (res);
}

void sort_5(t_ps *ps)
{
	int min;
	int max;

	min = find_min(ps);
	max = find_max(ps);
	// printf("1\n");
	// print_stack(ps);
	while (ps->a_len > 3)
	{
		if (ps->stack_a[0].place == min || ps->stack_a[0].place == max)
			pb(ps);
		else
			ra(ps);
	}

	sort_3(ps);
	// printf("2\n");
	// print_stack(ps);
	pa(ps);
	pa(ps);
	if (ps->stack_a[0].place > ps->stack_a[1].place)
		ra(ps);
	else
	{
		sa(ps);
		ra(ps);
	}
	print_stack(ps);
//	 printf("op 5 %d\n", ps->opers);

}
