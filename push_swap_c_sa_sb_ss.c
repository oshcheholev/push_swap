/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c_sa_sb_ss.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:10:03 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 13:10:25 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_ps *ps)
{
	t_elem	temp;

	write(1, "sa\n", 3);
	if (ps->a_len > 1)
	{
		temp = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = temp;
		ps->opers++;
	}
}

void	sb(t_ps *ps)
{
	t_elem	temp;

	write(1, "sb\n", 3);
	if (ps->b_len > 1)
	{
		temp = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = temp;
		ps->opers++;
	}
}

void	ss(t_ps *ps)
{
	t_elem	temp;

	write(1, "ss\n", 3);
	ps->opers++;
	if (ps->a_len > 1)
	{
		temp = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = temp;
		ps->opers++;
	}
	if (ps->b_len > 1)
	{
		temp = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = temp;
		ps->opers++;
	}
}
