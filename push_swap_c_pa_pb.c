/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_c_pa_pb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:07:14 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 13:07:31 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rm_from_b_for_pa(t_ps *ps)
{
	t_elem	*temp;
	int		i;

	i = 0;
	if (ps->b_len > 0)
	{
		temp = malloc((ps->b_len - 1) * sizeof(t_elem));
		if (!temp)
			err_exit(ps, "rm b");
		while (i < ps->b_len - 1)
		{
			temp[i] = ps->stack_b[i + 1];
			i++;
		}
		ps->b_len--;
		free(ps->stack_b);
		ps->stack_b = temp;
	}
}

void	rm_from_a_for_pb(t_ps *ps)
{
	t_elem	*temp;
	int		i;

	i = 0;
	if (ps->a_len > 0)
	{
		temp = malloc((ps->a_len - 1) * sizeof(t_elem));
		if (!temp)
			err_exit(ps, "rm a");
		while (i < ps->a_len - 1)
		{
			temp[i] = ps->stack_a[i + 1];
			i++;
		}
		ps->a_len--;
		free(ps->stack_a);
		ps->stack_a = temp;
	}
}

void	pa(t_ps *ps)
{
	t_elem	*temp;
	int		i;

	write(1, "pa\n", 3);
	if (ps->b_len > 0)
	{
		i = 1;
		temp = malloc((ps->a_len + 1) * sizeof(t_elem));
		if (!temp)
			err_exit(ps, "pa");
		temp[0] = ps->stack_b[0];
		while (i <= ps->a_len)
		{
			temp[i] = ps->stack_a[i - 1];
			i++;
		}
		ps->a_len++;
		free(ps->stack_a);
		ps->stack_a = temp;
		rm_from_b_for_pa(ps);
		ps->opers++;
	}
}

void	pb(t_ps *ps)
{
	t_elem	*temp;
	int		i;

	write(1, "pb\n", 3);
	if (ps->a_len > 0)
	{
		i = 1;
		temp = malloc((ps->b_len + 1) * sizeof(t_elem));
		if (!temp)
			err_exit(ps, "pb");
		temp[0] = ps->stack_a[0];
		while (i <= ps->b_len)
		{
			temp[i] = ps->stack_b[i - 1];
			i++;
		}
		ps->b_len++;
		free(ps->stack_b);
		ps->stack_b = temp;
		rm_from_a_for_pb(ps);
		ps->opers++;
	}
}
