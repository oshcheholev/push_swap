/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:10:25 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/01 15:29:43 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_ps *ps)
{
	t_elem temp;
	
	write(1, "sa\n", 3);
	if (ps->a_len > 1)
	{
		temp = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = temp;
		ps->opers++;
	}
}

void sb(t_ps *ps)
{
	t_elem temp;
	
	write(1, "sb\n", 3);
	if (ps->b_len > 1)
	{
		temp = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = temp;
		ps->opers++;
	}
}

void ss(t_ps *ps)
{
	write(1, "ss\n", 3);
	sa(ps);
	sb(ps);
	ps->opers++;
}

void rm_from_b_for_pa(t_ps *ps)
{
	t_elem *temp;
	int i;
	
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

void rm_from_a_for_pb(t_ps *ps)
{
	t_elem *temp;
	int i;
	
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

void pa(t_ps *ps)
{
	t_elem *temp;
	int i;
	
	
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

void pb(t_ps *ps)
{
	t_elem *temp;
	int i;
	
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

void ra(t_ps *ps)
{
	if (ps->a_len > 1)
	{
		t_elem temp;
		int i;
		
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

void rb(t_ps *ps)
{
	t_elem temp;
	int i;

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

void ra_for_rr(t_ps *ps)
{
	if (ps->a_len > 1)
	{
		t_elem temp;
		int i;
		
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


void rb_for_rr(t_ps *ps)
{
	t_elem temp;
	int i;

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

void rr(t_ps *ps)
{
	write(1, "rr\n", 3);
	ra_for_rr(ps);
	rb_for_rr(ps);
	ps->opers++;
}

void rra(t_ps *ps)
{
	t_elem temp;
	int i;

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

void rrb(t_ps *ps)
{
	t_elem temp;
	int i;
	
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

void rra_for_rrr(t_ps *ps)
{
	t_elem temp;
	int i;

	i = ps->a_len - 1;
	temp = ps->stack_a[ps->a_len - 1];
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = temp;
}

void rrb_for_rrr(t_ps *ps)
{
	t_elem temp;
	int i;
	
	i = ps->b_len - 1;
	temp = ps->stack_b[ps->b_len - 1];
	while (i > 0)
	{
		ps->stack_b[i] = ps->stack_b[i - 1];
		i--;
	}
	ps->stack_b[0] = temp;
}

void rrr(t_ps *ps)
{
	write(1, "rrr\n", 4);
	rra_for_rrr(ps);
	rrb_for_rrr(ps);
	ps->opers++;
}
