/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_prepare_a.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:38:57 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 15:45:11 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prepare_top(t_ps *ps)
{
	while (ps->ras > 0 && ps->rbs > 0)
	{
		rr(ps);
		ps->ras--;
		ps->rbs--;
	}
	while (ps->ras > 0)
	{
		ra(ps);
		ps->ras--;
	}
}

void	prepare_bot(t_ps *ps)
{
	while (ps->rras > 0 && ps->rrbs > 0)
	{
		rrr(ps);
		ps->rras--;
		ps->rrbs--;
	}
	while (ps->rras > 0)
	{
		rra(ps);
		ps->rras--;
	}
}

void	prepare_a(t_ps *ps)
{
	if (ps->to_top == 1)
		prepare_top(ps);
	else
		prepare_bot(ps);
}
