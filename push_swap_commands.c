/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:10:25 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 15:05:42 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_ps *ps)
{
	t_elem	temp;
	int		i;

	if (ps->a_len > 1)
	{
		write(1, "ra\n", 3);
		i = 0;
		temp = ps->stack_a[0];
		while (i < ps->a_len - 1)
		{
			ps->stack_a[i] = ps->stack_a[i + 1];
			i++;
		}
		ps->stack_a[i] = temp;
		ps->opers++;
	}
}

void	rb(t_ps *ps)
{
	t_elem	temp;
	int		i;

	write(1, "rb\n", 3);
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
		ps->opers++;
	}
}

void	rra(t_ps *ps)
{
	t_elem	temp;
	int		i;

	write(1, "rra\n", 4);
	i = ps->a_len - 1;
	temp = ps->stack_a[ps->a_len - 1];
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = temp;
	ps->opers++;
}

void	rrb(t_ps *ps)
{
	t_elem	temp;
	int		i;

	write(1, "rrb\n", 4);
	i = ps->b_len - 1;
	temp = ps->stack_b[ps->b_len - 1];
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = temp;
	ps->opers++;
}
