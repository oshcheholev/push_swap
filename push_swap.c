/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:44:56 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 15:03:24 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <string.h>

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
