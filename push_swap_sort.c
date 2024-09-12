/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:08:12 by oshcheho          #+#    #+#             */
/*   Updated: 2024/09/12 15:50:50 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	find_min_max(t_ps *ps)
// {
// 	int	i;

// 	i = 0;
// 	ps->min = ps->stack_a[0];
// 	ps->max = ps->stack_a[0];
// 	while (i < ps->a_len)
// 	{
// 		if (ps->stack_a[i] > ps->max)
// 			ps->max = ps->stack_a[i];
// 		if (ps->stack_a[i] < ps->min)
// 			ps->min = ps->stack_a[i];
// 		i++;
// 	}
// }

// void	my_sort(t_ps *ps)
// {
// 	find_min_max(ps);
// 	int initial_len;
// 	int pivot;

// 	initial_len = ps->a_len;
// 	pivot = (ps->min + ps->max) / 2;
	
// 	while(ps->a_len > initial_len / 2)
// 	{
// 		if (ps->stack_a[0] <= pivot)
// 			pb(ps);
// 		else
// 			ra(ps);
// 	}
// 	if (ps->a_len > 1)
// 		my_sort(ps) ;
// 	while (ps->b_len > 0)
// 		pa(ps);
// 	if (ps->a_len > 1)
// 		my_sort(ps) ;
// }

// void	my_sort(t_ps *ps)
// {
// 	int pivot;
// 	int count;
// 	int initial_len;

// 	find_min_max(ps);
// 	initial_len = ps->a_len;
// 	pivot = (ps->min + ps->max) / 2;
// 	count = 0;

// 	while (count < initial_len)
// 	{
// 		if (ps->stack_a[0] <= pivot)
// 			pb(ps);
// 		else
// 			ra(ps);
// 		count++;
// 	}

// 	// Sort the remaining elements
// 	if (ps->a_len > 1)
// 		my_sort(ps);
	
// 	// Push elements back to stack_a
// 	while (ps->b_len > 0)
// 		pa(ps);
// }

// void find_max(t_ps *ps)
// {
// 	int max;
// 	int i;
	
// 	i = 0;
// 	max = ps->stack_a[0];
// 	while (i < ps->a_len)
// 	{
// 		if (ps->stack_a[i] > max)
// 			max = ps->stack_a[i];
// 		i++;
// 	}
// 	ps->max = max;
// }

// void my_sort(t_ps *ps)
// {
// 	find_max(ps);
// 	int i;
// 	int j;
// 	int max_bits;
// 	int count;
// 	int operations;

// 	count = ps->a_len;
// 	i = 0;
// 	j = 0;
// 	max_bits = 0;

// 	operations = 0;
// 	while ((ps->max >> max_bits) != 0)
// 		max_bits++;
// 	while (i < max_bits)
// 	{
// 		while (j < count)
// 		{
// 			if ((ps->stack_a[0] >> i) & 1)
// 			{
// 				ra(ps);
// 				operations++;
// 			}
// 			else
// 			{
// 				pb(ps);
// 				operations++;
// 			}
// 			j++;
// 		}
// 		j = 0;
// 		while (ps->b_len > 0)
// 		{
// 			pa(ps);
// 			operations++;
// 		}
// 		i++;
// 	}
// 	printf("operations  %d\n", operations);
// }

int	*create_temp_arr(t_ps *ps)
{
	int	i;
	int	*res;
	
	i = 0;
	// while (i < ps->a_len)
	// {
	// 	printf("1 %d\n", ps->stack_a[i].value);
	// 	i++;
	// }

	i = 0;
	res = malloc(ps->a_len * sizeof(int));
	if (!res)
		return (free(res), NULL);
	while (i < ps->a_len)
	{
		res[i] = ps->stack_a[i].value;
		i++;
	}
	i = 0;
	return (res);
}
int *temp_sort_arr(t_ps *ps)
{
	int	i;
	int j;
	int	*res;
	int temp;

	res = create_temp_arr(ps);
	i = 0;
	// while (i < ps->a_len)
	// {
	// 	printf("temp sort   %d   %d\n", ps->a_len, ps->stack_a[i].value);
	// 	i++;
	// }
	if (!res)
		return (free(res), NULL);
	i = ps->a_len - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			// printf("aaa  %d %d %d %d \n", i, j, res[j], res[j + 1]);
			if (res[j] > res[j + 1])
			{
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
			}
			j++;
		}
		i--;
	}
	i = 0;
	return (res);
}

void assign_place(t_ps *ps)
{
	int i;
	int j;
	int *arr;

	i = 0;
	j = 0;
	arr = temp_sort_arr(ps);
	if (!arr)
		return (free(arr));
	while(i < ps->a_len)
	{
		while(j < ps->a_len)
		{
			if (ps->stack_a[j].value == arr[i])
			ps->stack_a[j].place = i;
			j++;
		}
		j = 0;
		i++;
	}
	free(arr);	
	// i = 0;
	// while (i < ps->a_len)
	// {
	// 	printf("value  %d   place %d\n", ps->stack_a[i].value, ps->stack_a[i].place);
	// 	i++;
	// }
}

void	main_sort(t_ps *ps, int i, int top_or_bot)
{
	int j;

	j = 0;
	while(j < i)
	{
		if (top_or_bot == 0)
		{
				ra(ps);
				j++;
		}
		else if (top_or_bot == 1)
		{
				rra(ps);
				j++;
		}
	}
			pb(ps);
}

void	push_back(t_ps *ps)
{
	
	int i;

	i = 0;
	// while (i < 0)
	// {
//		main_sort(ps, 0);
	// 	i--;
	// }
	i = 0;
	// while (i < ps->b_len)
	// {
	// 	printf("b before push  value  %d   place %d\n", ps->stack_b[i].value, ps->stack_b[i].place);
	// 	i++;
	// }

	while (ps->b_len > 0)
	{
		pa(ps);
	}

	i = 0;
	while (i < ps->a_len)
	{
		printf("a after push  value  %d   place %d\n", ps->stack_a[i].value, ps->stack_a[i].place);
		i++;
	}

}

void	init_price(t_ps *ps)
{
	int	i;
	
	i = 0;
	while (i < ps->a_len)
	{
		ps->stack_a[i].price_top = -1;
		ps->stack_a[i].price_bot = -1;
		i++;
	}
	ps->el_from_top = 0;
	ps->el_from_bot = ps->a_len - 1;
}

void find_min_place (t_ps *ps)
{
	int i;
	int top_or_bot;
	int min_price;

	i = 0;
	top_or_bot = 0;
	min_price = ps->stack_a[0].price_top;
	while (i < ps->a_len)
	{
		if (ps->stack_a[i].price_top < min_price)
		{
			min_price = ps->stack_a[i].price_top;
			top_or_bot = 0;
		}
		else if (ps->stack_a[i].price_bot < min_price)
		{
			min_price = ps->stack_a[i].price_bot;
			top_or_bot = 1;
		}
		i++;
	} 
	main_sort(ps, min_price, top_or_bot);
}

void find_element (t_ps *ps, int i)
{
	int j;
	int price_top;
	int price_bot;
		
	assign_place(ps);
	init_price(ps);
	price_top = 0;
	price_bot = 0;

	j = 0;
	while (j < ps->a_len)
	{
		price_top = ps->stack_a[j].place + j + i;
		ps->stack_a[j].price_top = price_top;
		price_bot = ps->a_len - ps->stack_a[j].place - i;
		ps->stack_a[j].price_bot = price_bot;
		printf("val %d place %d  price_top %d price_bot %d\n", ps->stack_a[j].value, ps->stack_a[j].place, ps->stack_a[j].price_top, ps->stack_a[j].price_bot);

		j++;
	}
	while (ps->a_len > 1)
	{
		printf("a_len  %d\n", ps->a_len);
	}
//		find_min_place(ps);
}

void push_to_b(t_ps *ps, int count)
{
	int i;
	int j;

	j = 0;
	while (j < ps->a_len)
	{
		printf("val %d place %d count %d\n", ps->stack_a[j].value, ps->stack_a[j].place, count);
		j++;
	}
	i = 0;
	j = 0;
	while (ps->stack_a[i].place != count)
		i++;
	while (ps->stack_a[ps->a_len - j - 1].place != count)
	{
		printf("place %d   j %d\n", ps->stack_a[ps->a_len - j - 1].place, j);
		j++;
	}
	printf("i %d   j %d\n", i, j);
	
	if (i <= j)
	{
		while (i > 0)
		{
			ra(ps);
			i--;
		}
		printf("pushing i val %d place %d\n", ps->stack_a[0].value, ps->stack_a[0].place);
		pb(ps);
	}
	else
	{
		while (j >= 0)
		{
			rra(ps);
			j--;
		}
		printf("pushing j val %d place %d\n", ps->stack_a[0].value, ps->stack_a[0].place);
		pb(ps);
//		rb(ps);
	}
	j = 0;
	while (j < ps->a_len)
	{
		printf("remained val %d place %d count %d\n", ps->stack_a[j].value, ps->stack_a[j].place, count);
		j++;
	}

	j = 0;
	while (j < ps->b_len)
	{
		printf("in b val %d place %d count %d\n", ps->stack_b[j].value, ps->stack_b[j].place, count);
		j++;
	}


//	ra(ps);
}

// void push_to_b_2(t_ps *ps)
// {
// 	int	i;
	
// 	i = 0;
// 	while (i < ps->a_len)
// 	{
		
// 	}
// 	ps->to_move = ps->a_len / 2;
	
	
// }

void start_sort(t_ps *ps)
{
	int i;
	
	i = 0;
	while (ps->a_len > 2)
	{
		push_to_b(ps, i);
		i++;		
	}
	printf("a0 %d   a1 %d\n", ps->stack_a[0].value, ps->stack_a[1].value);
	if (ps->stack_a[0].value > ps->stack_a[1].value)
		ra(ps);
	
	
//	find_element(ps, 0);
	push_back(ps);	
}

void push_to_b1(t_ps *ps, int price)
{
	int i;

	i = 0;
	while (i < price)
	{
		ra(ps);
		i++;
	}
	pb(ps);
}
void move_to_top(t_ps *ps, int elem)
{
	int i;
	i = 0;
	printf("el %d\n", elem);
	while (i < elem)
	{
		ra(ps);
		i++;
	}
	pb(ps);
}

void move_to_bot(t_ps *ps, int elem)
{
	int i;
	i = 0;
	while (i <= elem)
	{
		rra(ps);
		i++;
	}
	pb(ps);
}

void move_elem(t_ps *ps, int what, int toporbot, int rotate)
{
	int i;
	i = 0;
	if (toporbot == 0)
	{
		while (i <= what)
		{
			ra(ps);
			i++;
		}
		pb(ps);
	}
	if (toporbot == 1)
	{
		while (i <= what)
		{
			rra(ps);
			i++;
		}
		pb(ps);
	if (rotate)
		rb(ps);
	}
}

void set_prices(t_ps *ps)
{
	int i;

	init_price(ps);
	i = 0;
	while(i < ps->a_len)
	{
		if (ps->stack_a[i].place == 0 || ps->stack_a[i].place == ps->a_len - 1)
		{
			ps->stack_a[i].price_top = i + ps->stack_a[i].place;
			ps->stack_a[i].price_bot = ps->a_len - ps->stack_a[i].place;
		}
		i++;
	}
	i = 0;
	while(i < ps->a_len)
	{
		printf("val %d  place  %d  pr_t  %d  pr_b  %d \n", ps->stack_a[i].value, ps->stack_a[i].place, ps->stack_a[i].price_top, ps->stack_a[i].price_bot);
		i++;
	}
}
void	move_to_b1(t_ps *ps)
{
	int i;
	int move_top;
	int move_bot;
	int to_move[3];

	move_top = -1;
	move_bot = -1;
	
	i = 0;
	while (ps->a_len > 1)
	{
		assign_place(ps);
//		set_prices(ps);
		while (i < ps->a_len) 
		{
			if (ps->stack_a[i].place == 0)
			{
				if (i <= ps->a_len / 2)
				{
					move_top = i;
					to_move[1] = 0;
				}
				else
				{
					move_top = ps->a_len - i;
					to_move[1] = 1;
				}
			}
			if (ps->stack_a[i].place == ps->a_len - 1)
			{
				if (i <= ps->a_len - i)
				{
					move_bot = i;
					to_move[1] = 0;
				}
				else
				{
					move_bot = ps->a_len - i;
					to_move[1] = 1;
				}
			}

			i++;
		}
		printf("top %d bot %d\n", move_bot, move_bot);
		if (move_top <= move_bot)
		{
			to_move[2] = 0;
			move_elem(ps, move_top, to_move[1], to_move[2]);
		}
		else
		{
			to_move[2] = 1;
			move_elem(ps, move_bot, to_move[1], to_move[2]);
		}
	}
	test_print(ps);
	
}






void test(t_ps *ps)
{
	move_to_b1(ps);
}