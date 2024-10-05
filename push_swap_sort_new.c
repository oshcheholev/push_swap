/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:04:03 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/04 12:39:36 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

void	set_move(t_ps *ps, int i)
{
	ps->ras = ps->stack_b[i].ras;
	ps->rbs = ps->stack_b[i].rbs;
	ps->rras = ps->stack_b[i].rras;
	ps->rrbs = ps->stack_b[i].rrbs;
	ps->ras_total = ps->stack_b[i].ras;
	ps->rras_total = ps->stack_b[i].rras;
	if (ps->stack_b[i].place > ps->middle)
		ps->to_top = 0;
	else
		ps->to_top = 1;
}

void	find_min_moves(t_ps *ps)
{
	int	i;

	i = 0;
	init_moves(ps);
	find_rbs_rrbs(ps);
	find_ras_rras(ps);
	while (i < ps->b_len)
	{
		if (ps->stack_b[i].rbs >= 0)
			ps->stack_b[i].m_m += ps->stack_b[i].rbs + 2;
		if (ps->stack_b[i].rrbs >= 0)
			ps->stack_b[i].m_m += ps->stack_b[i].rrbs + 2;
		if (ps->stack_b[i].to_top == 1)
		{
			ps->stack_b[i].m_m += ps->stack_b[i].ras;
			ps->stack_b[i].m_m += (ft_abs(ps->stack_b[i].place - ps->middle));
		}
		if (ps->stack_b[i].to_top == 0)
		{
			ps->stack_b[i].m_m += ps->stack_b[i].rras;
			ps->stack_b[i].m_m += ft_abs(ps->stack_b[i].place - ps->middle);
		}
		i++;
	}
}

int	find_min_el(t_ps *ps)
{
	int	i;
	int	min_el;
	int	min_moves;

	i = 0;
	min_el = 0;
	find_min_moves(ps);
	min_moves = ps->stack_b[0].m_m;
	while (i < ps->b_len)
	{
		if (ps->stack_b[i].m_m < min_moves)
		{
			min_moves = ps->stack_b[i].m_m;
			min_el = i;
		}
		i++;
	}
	return (min_el);
}

void	put_el_to_a(t_ps *ps)
{
	int	min_el;

	if (ps->first_move == 0)
		restore_a(ps);
	min_el = find_min_el(ps);
	set_move(ps, min_el);
	prepare_a(ps);
	while (ps->rbs > 0)
	{
		rb(ps);
		ps->rbs--;
	}
	while (ps->rrbs >= 0)
	{
		rrb(ps);
		ps->rrbs--;
	}
	pa(ps);
	ps->first_move = 0;
}
