/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:02:44 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 13:04:31 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_for_rr(t_ps *ps)
{
	t_elem	temp;
	int		i;

	if (ps->a_len > 1)
	{
		i = 0;
		temp = ps->stack_a[0];
		while (i < ps->a_len - 1)
		{
			ps->stack_a[i] = ps->stack_a[i + 1];
			i++;
		}
		ps->stack_a[i] = temp;
	}
}

void	rb_for_rr(t_ps *ps)
{
	t_elem	temp;
	int		i;

	if (ps->a_len > 1)
	{
		i = 0;
		temp = ps->stack_b[0];
		while (i < ps->b_len - 1)
		{
			ps->stack_b[i] = ps->stack_b[i + 1];
			i++;
		}
		ps->stack_b[i] = temp;
	}
}

void	rr(t_ps *ps)
{
	write(1, "rr\n", 3);
	ra_for_rr(ps);
	rb_for_rr(ps);
	ps->opers++;
}
