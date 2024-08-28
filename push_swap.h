/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:03:54 by oshcheho          #+#    #+#             */
/*   Updated: 2024/08/28 15:55:41 by oshcheho         ###   ########.fr       */
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

typedef struct s_ps
{
	int		min;
	int		max;
	int		a_len;
	int		b_len;
	int		*stack_a;
	int		*stack_b;
}			t_ps;



int		ft_atoi(const char *nptr);
int		ft_atoi_new(const char *nptr, t_ps *ps);
void	process_input(t_ps *ps, char *str);
void	arr_or_not(t_ps *ps, int argc, char **argv);
void	test_print(t_ps *ps);
void	err_exit(t_ps *ps);
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


#endif