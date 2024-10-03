/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c_rrr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:04:46 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 13:05:20 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_for_rrr(t_ps *ps)
{
	t_elem	temp;
	int		i;

	i = ps->a_len - 1;
	temp = ps->stack_a[ps->a_len - 1];
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = temp;
}

void	rrb_for_rrr(t_ps *ps)
{
	t_elem	temp;
	int		i;

	i = ps->b_len - 1;
	temp = ps->stack_b[ps->b_len - 1];
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = temp;
}

void	rrr(t_ps *ps)
{
	write(1, "rrr\n", 4);
	rra_for_rrr(ps);
	rrb_for_rrr(ps);
	ps->opers++;
}
