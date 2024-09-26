/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:03:54 by oshcheho          #+#    #+#             */
/*   Updated: 2024/09/26 14:20:08 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct s_elem
{
	int		value;
	int		place;
	int		price;
	int		price_top;
	int		price_bot;
	int		price_min;
	int		rotate_a;
	int		rotate_b;
	int		to_move_top;
	int		to_move_bot;
}			t_elem;

typedef struct s_ps
{
	int		to_move;
	int		middle;
	int		el_from_top;
	int		el_from_bot;
	int		price_top;
	int		price_bot;
	int		opers;
	int		min;
	int		max;
	int		a_len;
	int		b_len;
	t_elem	*stack_a;
	t_elem	*stack_b;
}			t_ps;


void	test(t_ps *ps);
void sort_5(t_ps *ps);
void	main_sort(t_ps *ps);
int		ft_atoi(const char *nptr);
int		ft_atoi_new(const char *nptr, t_ps *ps);
void	process_input(t_ps *ps, char *str);
void	arr_or_not(t_ps *ps, int argc, char **argv);
void	test_print(t_ps *ps);
void	err_exit(t_ps *ps, char *msg);
void	sa(t_ps *ps);
void	sb(t_ps *ps);
void	ss(t_ps *ps);
void	pa(t_ps *ps);
void	pb(t_ps *ps);
void	ra(t_ps *ps);
void	rb(t_ps *ps);
void	rr(t_ps *ps);
void	rra(t_ps *ps);
void	rrb(t_ps *ps);
void	rrr(t_ps *ps);
void	my_sort(t_ps *ps);
int		*temp_sort_arr(t_ps *ps);
void	assign_place(t_ps *ps);
void	push_back(t_ps *ps);
void find_element (t_ps *ps, int i);
void start_sort(t_ps *ps);

#endif