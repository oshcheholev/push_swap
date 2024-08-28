/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:44:56 by oshcheho          #+#    #+#             */
/*   Updated: 2024/08/28 15:56:00 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// int *arr;
	int i;
	int j;
	char **if_arr;
	t_ps	ps;

	if_arr = NULL;
	ps.stack_a = NULL;
	ps.stack_b = NULL;
	
	i = 0;
	j = 0;
	ps.a_len = argc - 1;
	ps.b_len = 0;
	
	arr_or_not(&ps, argc, argv);
	ps.stack_b = NULL;

	my_sort(&ps);
	// sa(&ps);
	
	// pb(&ps);
	// pb(&ps);
	// pb(&ps);
	
	// ra(&ps);
	// rb(&ps);
	
	// rra(&ps);
	// rrb(&ps);
	
	// sa(&ps);

	// pa(&ps);
	// pa(&ps);
	// pa(&ps);

	test_print(&ps);
	
	// pb(&ps);
	// test_print(&ps);

	// pb(&ps);
	// test_print(&ps);

	// ra(&ps);
	// test_print(&ps);

	// rb(&ps);
	// test_print(&ps);
	// rr(&ps);
	// test_print(&ps);

	// rra(&ps);
	// test_print(&ps);
	// rrb(&ps);
	// test_print(&ps);

	// rrr(&ps);
	// test_print(&ps);
	
	free(ps.stack_a);
	free(ps.stack_b);

//	arr = process_input(argv[1]);
// 	while (i < argc - 1)
// 	{
// //		free(if_arr);
// //		printf("argv i %s\n", argv[i + 1]);

// 		if_arr = ft_split(argv[i + 1], ' ');
// 		while (if_arr[j] != NULL)
// 		{
// //		arr[i] = ft_atoi_new(ft_split(argv[i + 1], ' '));
// 			/* code */
// 		printf("arr i %s\n", if_arr[j]);
// 		j++;
// 		}
		
// 		i++;
// 	}
	// i = 0;
	// while (i < argc - 1)
	// {
	// 	printf("i %d , argc %d  arr_i %d argv[i] %s\n",i,  argc, arr[i], argv[i]);
	// 	i++;
	// }

}