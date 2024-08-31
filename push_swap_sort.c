/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 15:08:12 by oshcheho          #+#    #+#             */
/*   Updated: 2024/08/31 18:49:49 by oshcheho         ###   ########.fr       */
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
	while (i < ps->a_len)
	{
		printf("yyy   %d   %d\n", ps->a_len, ps->stack_a[i].value);
		i++;
	}
	if (!res)
		return (free(res), NULL);
	i = ps->a_len - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
			printf("aaa  %d %d %d %d \n", i, j, res[j], res[j + 1]);
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

void	main_sort(t_ps *ps, int i)
{
	// int i;
	int j;
	int k;
	
	// i = 0;
	k = 0;
//	while (i < (ps->a_len - 1))
//	{
		j = 0;
		while(k < ps->a_len)
		{
//		printf("k  %d   i %d  value %d   place  %d\n", k, i, ps->stack_a[k].value, ps->stack_a[k].place);
			
			if (ps->stack_a[k].place == i)
			
			{
//		printf("a[]k  %d   i %d\n", ps->stack_a[k].value, i);
				while (j < k)
				{
					ra(ps);
					j++;
				}
				pb(ps);
//				opers++;	
//				break;
			}
				k++;
		}
		i++;
//		main_sort(ps, i);
		
//		i++;
//	}
//		main_sort(ps);
	
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

	// i = 0;
	// while (i < ps->a_len)
	// {
	// 	printf("a after push  value  %d   place %d\n", ps->stack_a[i].value, ps->stack_a[i].place);
	// 	i++;
	// }

}

void init_price(t_ps *ps)
{
	int i;
	
	i = 0;
	while (i < ps->a_len)
	{
		ps->stack_a[i].price_top = 0;
		ps->stack_a[i].price_bot = 0;
		i++;
	}
}

void find_element (t_ps *ps, int i)
{
	int j;
	int len;
	int price;
	int k;
	
	init_price(ps);
	k = 0;
	price = 0;
	len = ps->a_len / 2;
	while(k < len)
	{
		price = ps->stack_a[k].place - i + k;
		ps->stack_a[k].price_top = price;
		price = ps->stack_a[ps->a_len - k].place - i + k + 1;
		ps->stack_a[ps->a_len - k].price_bot = price;
//		printf ("k  %d  price  %d\n", k, price);
		k++;
	}
	i = 0;
	while (i < ps->a_len - 1)
	{
		printf ("price_top  %d   price_bot  %d\n", ps->stack_a[i].price_top, ps->stack_a[i].price_bot);
		i++;
	}

	i = 0;
	 
	if (ps->a_len == 1)
	{
//		printf("opers %d\n", i);
		return ;
	}
	
	j = ps->a_len - 1;

	if (ps->stack_a[0].place > ps->stack_a[1].place)
		sa(ps);
	if (ps->stack_a[0].place > ps->stack_a[j].place)
		rra(ps);
	main_sort(ps, i);
	i++;
	find_element(ps, i);
}

void start_sort(t_ps *ps)
{
	int i;
	
	i = 0;
	find_element(ps, 0);
	push_back(ps);	
}