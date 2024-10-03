/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:26:07 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 17:11:23 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_moves(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->b_len)
	{
		ps->stack_b[i].rbs = -1;
		ps->stack_b[i].rrbs = -1;
		ps->stack_b[i].ras = -1;
		ps->stack_b[i].rras = -1;
		ps->stack_b[i].m_m = 0;
		ps->stack_b[i].rbs_total = -1;
		ps->stack_b[i].rrbs_total = -1;
		ps->stack_b[i].ras_total = -1;
		ps->stack_b[i].rras_total = -1;
		i++;
	}
}

void	find_rbs_rrbs(t_ps *ps)
{
	int	i;

	init_moves(ps);
	i = 0;
	if (ps->b_len > 0)
	{
		while (i < ps->b_len)
		{
			if (ps->stack_b[i].place < ps->middle)
				ps->stack_b[i].to_top = 1;
			else
				ps->stack_b[i].to_top = 0;
			if (i <= ps->b_len / 2)
				ps->stack_b[i].rbs = i;
			else
				ps->stack_b[i].rrbs = ps->b_len - 1 - i;
			ps->stack_b[i].rbs_total = ps->stack_b[i].rbs;
			ps->stack_b[i].rrbs_total = ps->stack_b[i].rrbs;
			i++;
		}
	}
}

void	find_ras_top(t_ps *ps, int i)
{
	int	j;

	j = 0;
	while (j < ps->a_len && ps->stack_b[i].place > ps->stack_a[j].place)
		j++;
	ps->stack_b[i].ras = j;
}

void	find_ras_bot(t_ps *ps, int i)
{
	int	j;

	j = 0;
	while (j < ps->a_len
		&& ps->stack_b[i].place < ps->stack_a[ps->a_len - 1 - j].place)
		j++;
	ps->stack_b[i].rras = j;
}

void	find_ras_rras(t_ps *ps)
{
	int	i;

	i = 0;
	while (i < ps->b_len)
	{
		if (ps->stack_b[i].place < ps->stack_a[0].place)
			ps->stack_b[i].ras = 0;
		else
			find_ras_top(ps, i);
		if (ps->stack_b[i].place > ps->stack_a[ps->a_len - 1].place)
			ps->stack_b[i].rras = 0;
		else
			find_ras_bot(ps, i);
		ps->stack_b[i].ras_total = ps->stack_b[i].ras;
		ps->stack_b[i].rras_total = ps->stack_b[i].rras;
		i++;
	}
}
