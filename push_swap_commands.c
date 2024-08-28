/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_commands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:10:25 by oshcheho          #+#    #+#             */
/*   Updated: 2024/08/27 18:32:16 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_ps *ps)
{
	int temp;
	
	if (ps->a_len > 1)
	{
		temp = ps->stack_a[0];
		ps->stack_a[0] = ps->stack_a[1];
		ps->stack_a[1] = temp;
	}
}

void sb(t_ps *ps)
{
	int temp;
	
	if (ps->b_len > 1)
	{
		temp = ps->stack_b[0];
		ps->stack_b[0] = ps->stack_b[1];
		ps->stack_b[1] = temp;
	}
}

void ss(t_ps *ps)
{
	sa(ps);
	sb(ps);
}

void rm_from_b_for_pa(t_ps *ps)
{
	int *temp;
	int i;
	
	i = 0;
	temp = malloc((ps->b_len - 1) * sizeof(int));
	if (!temp)
		err_exit(ps);
	while (i < ps->b_len - 1)
	{
		temp[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->b_len--;
	free(ps->stack_b);
	ps->stack_b = temp;
}

void rm_from_a_for_pb(t_ps *ps)
{
	int *temp;
	int i;
	
	i = 0;
	temp = malloc((ps->a_len - 1) * sizeof(int));
	if (!temp)
		err_exit(ps);
	while (i < ps->a_len - 1)
	{
		temp[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->a_len--;
	free(ps->stack_a);
	ps->stack_a = temp;
}

void pa(t_ps *ps)
{
	int *temp;
	int i;
	
	printf("PA\n\n");
	i = 1;
	temp = malloc((ps->a_len + 1) * sizeof(int));
	if (!temp)
		err_exit(ps);
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
}

void pb(t_ps *ps)
{
	int *temp;
	int i;
	
	printf("PB\n\n");
	i = 1;
	temp = malloc((ps->b_len + 1) * sizeof(int));
	if (!temp)
		err_exit(ps);
	temp[0] = ps->stack_a[0];
	while (i <= ps->b_len)
	{
		temp[i] = ps->stack_b[i - 1];
		// printf("t %d", temp[i]);
		i++;
	}
	ps->b_len++;
	free(ps->stack_b);
	ps->stack_b = temp;
	rm_from_a_for_pb(ps);
}

void ra(t_ps *ps)
{
	int temp;
	int i;
	
	printf("RA\n\n");
	i = 0;
	temp = ps->stack_a[0];
	while (i < ps->a_len - 1)
	{
		ps->stack_a[i] = ps->stack_a[i + 1];
		i++;
	}
	ps->stack_a[i] = temp;
}

void rb(t_ps *ps)
{
	int temp;
	int i;
	
	printf("RB\n\n");
	i = 0;
	temp = ps->stack_b[0];
	while (i < ps->b_len - 1)
	{
		ps->stack_b[i] = ps->stack_b[i + 1];
		i++;
	}
	ps->stack_b[i] = temp;
}

void rr(t_ps *ps)
{
	ra(ps);
	rb(ps);
}

void rra(t_ps *ps)
{
	int temp;
	int i;
	
	printf("RRA\n\n");
	i = ps->a_len - 1;
	temp = ps->stack_a[ps->a_len - 1];
	while (i > 0)
	{
		ps->stack_a[i] = ps->stack_a[i - 1];
		i--;
	}
	ps->stack_a[0] = temp;
}

void rrb(t_ps *ps)
{
	int temp;
	int i;
	
	printf("RRB\n\n");
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
	rra(ps);
	rrb(ps);
}
