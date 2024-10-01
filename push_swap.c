/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:44:56 by oshcheho          #+#    #+#             */
/*   Updated: 2024/09/27 16:16:13 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	// int *arr;
	// int i;
	// int j;
//	char **if_arr;
	t_ps	ps;

	ps.opers = 0;
//	if_arr = NULL;
	ps.stack_a = NULL;
	ps.stack_b = NULL;
	
//	i = 0;
//	j = 0;
	ps.a_len = argc - 1;
	ps.b_len = 0;
	
	arr_or_not(&ps, argc, argv);
	ps.stack_b = NULL;
//	i = 0;
	// while (i < ps.a_len)
	// {
	// 	printf("1AAAAAAAAAAAA %d\n", ps.stack_a[i].value);
	// 	i++;
	// }

	//my_sort(&ps);
//	temp_sort_arr(&ps);
	assign_place(&ps);
	ps.middle = ps.a_len / 2;

//	test_print(&ps);
//	push_back(&ps);
//	find_element(&ps, 0);
//	start_sort(&ps);
//	test(&ps);
	new_sort(&ps);	
//	print_stack(&ps);		
//	printf("opers: %d\n", ps.opers);

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