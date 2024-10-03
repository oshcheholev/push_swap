/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:15:16 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 15:36:33 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_ps *ps)
{
	if (ps->stack_a[0].place == ps->middle - 1
		&& ps->stack_a[1].place == ps->middle)
		return ;
	if (ps->stack_a[0].place == ps->middle - 1
		&& ps->stack_a[1].place == ps->middle + 1)
	{
		rra(ps);
		sa(ps);
	}
	if (ps->stack_a[0].place == ps->middle
		&& ps->stack_a[1].place == ps->middle + 1)
		rra(ps);
	if (ps->stack_a[0].place == ps->middle
		&& ps->stack_a[1].place == ps->middle - 1)
		sa(ps);
	if (ps->stack_a[0].place == ps->middle + 1
		&& ps->stack_a[1].place == ps->middle - 1)
		ra(ps);
	if (ps->stack_a[0].place == ps->middle + 1
		&& ps->stack_a[1].place == ps->middle)
	{
		sa(ps);
		rra(ps);
	}
}

int	find_min(t_ps *ps)
{
	int	i;
	int	res;

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

int	find_max(t_ps *ps)
{
	int	i;
	int	res;

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

void	sort_4(t_ps *ps)
{
	int	min;

	min = find_min(ps);
	while (ps->a_len > 3)
	{
		if (ps->stack_a[0].place == min)
			pb(ps);
		else
			ra(ps);
	}
	sort_3(ps);
	pa(ps);
}

void	sort_5(t_ps *ps)
{
	int	min;
	int	max;

	min = find_min(ps);
	max = find_max(ps);
	while (ps->a_len > 3)
	{
		if (ps->stack_a[0].place == min || ps->stack_a[0].place == max)
			pb(ps);
		else
			ra(ps);
	}
	sort_3(ps);
	pa(ps);
	pa(ps);
	if (ps->stack_a[0].place > ps->stack_a[1].place)
		ra(ps);
	else
	{
		sa(ps);
		ra(ps);
	}
}
