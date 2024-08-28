/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:08:12 by oshcheho          #+#    #+#             */
/*   Updated: 2024/08/28 16:20:08 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min_max(t_ps *ps)
{
	int	i;

	i = 0;
	ps->min = ps->stack_a[0];
	ps->max = ps->stack_a[0];
	while (i < ps->a_len)
	{
		if (ps->stack_a[i] > ps->max)
			ps->max = ps->stack_a[i];
		if (ps->stack_a[i] < ps->min)
			ps->min = ps->stack_a[i];
		i++;
	}
}

// void	my_sort(t_ps *ps)
// {
// 	find_min_max(ps);
// 	int initial_len;
// 	int pivot;

// 	initial_len = ps->a_len;
// 	pivot = (ps->min + ps->max) / 2;
	
// 	while(ps->a_len > initial_len / 2)
// 	{
// 		if (ps->stack_a[0] <= pivot)
// 			pb(ps);
// 		else
// 			ra(ps);
// 	}
// 	if (ps->a_len > 1)
// 		my_sort(ps) ;
// 	while (ps->b_len > 0)
// 		pa(ps);
// 	if (ps->a_len > 1)
// 		my_sort(ps) ;
// }

void	my_sort(t_ps *ps)
{
	int pivot;
	int count;
	int initial_len;

	find_min_max(ps);
	initial_len = ps->a_len;
	pivot = (ps->min + ps->max) / 2;
	count = 0;

	while (count < initial_len)
	{
		if (ps->stack_a[0] <= pivot)
			pb(ps);
		else
			ra(ps);
		count++;
	}

	// Sort the remaining elements
	if (ps->a_len > 1)
		my_sort(ps);
	
	// Push elements back to stack_a
	while (ps->b_len > 0)
		pa(ps);
}