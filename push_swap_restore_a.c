/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_restore_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:27:11 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 17:11:10 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	restore_top(t_ps *ps)
{
	if (ps->b_len > 1)
	{
		if (ps->stack_b[0].place == ps->stack_a[0].place - 1)
			pa(ps);
	}
	while (ps->ras_total > 0 && ps->rrbs > 0)
	{
		rrr(ps);
		ps->ras_total--;
		ps->rrbs--;
	}
	while (ps->ras_total > 0)
	{
		rra(ps);
		ps->ras_total--;
	}
}

void	restore_bot(t_ps *ps)
{
	{
		if (ps->b_len > 1)
		{
			if (ps->stack_b[0].place == ps->stack_a[ps->a_len - 1].place + 1)
			{
				pa(ps);
				ra(ps);
			}
		}
		while (ps->rras_total > 0 && ps->rbs > 0)
		{
			rr(ps);
			ps->rras_total--;
			ps->rbs--;
		}
		while (ps->rras_total > 0)
		{
			ra(ps);
			ps->rras_total--;
		}
	}
}

void	restore_a(t_ps *ps)
{
	if (ps->to_top == 1)
		restore_top(ps);
	else
	{
		ra(ps);
		restore_bot(ps);
	}
}
