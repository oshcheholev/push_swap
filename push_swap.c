/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:44:56 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/04 12:57:34 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_small(t_ps *ps)
{
	if (ps->a_len == 1)
		return ;
	if (ps->a_len == 2)
	{
		if (ps->stack_a[0].value > ps->stack_a[1].value)
			sa(ps);
	}
	if (ps->a_len == 3)
		sort_3(ps);
	if (ps->a_len == 4)
		sort_4(ps);
	if (ps->a_len == 5)
		sort_5(ps);
	if (ps->a_len > 5)
	{
		first_move_to_b(ps);
		ps->first_move = 1;
		sort_5(ps);
		while (ps->b_len > 0)
			put_el_to_a(ps);
		restore_a(ps);
	}
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	ps.opers = 0;
	ps.stack_a = NULL;
	ps.stack_b = NULL;
	ps.array = NULL;
	ps.a_len = argc - 1;
	ps.b_len = 0;
	arr_or_not(&ps, argc, argv);
	ps.stack_b = NULL;
	assign_place(&ps);
	ps.middle = ps.a_len / 2;
	sort_small(&ps);
	clean_arrs(&ps);
}
	// int i = 0;
	// while (i < ps.a_len)
	// {
	// 	printf("%d\n", ps.stack_a[i].value);
	// 	i++;
	// }
