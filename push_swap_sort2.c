
#include "push_swap.h"
#include <stdio.h>

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

void sort_3(t_ps *ps)
{
	if (ps->stack_a[0].place == ps->middle - 1)
	{
		if (ps->stack_a[1].place == ps->middle)
			return ;
		else
		{
			rra(ps);
			sa(ps);
		}
	}
	else if (ps->stack_a[0].place == ps->middle)
	{
		if (ps->stack_a[1].place == ps->middle + 1)
			rra(ps);
		else
			sa(ps);
	}
	else if (ps->stack_a[0].place == ps->middle + 1)
	{
		if (ps->stack_a[1].place == ps->middle - 1)
			ra(ps);
		else
		{
			sa(ps);
			rra(ps);
		}
	}
}

void print_stack(t_ps *ps) {
    printf("Stack A: ");
    for (int i = 0; i < ps->a_len; i++) {
        printf("%d ", ps->stack_a[i].place);
    }
    printf("\nStack B: ");
    for (int i = 0; i < ps->b_len; i++) {
        printf("%d ", ps->stack_b[i].place);
    }
    printf("\n");
}

int find_min(t_ps *ps)
{
	int i;
	int res;

	i = 0;
	res = ps->stack_a[0].place;
	while (i < ps->a_len)
	{
		if (ps->stack_a[i].place < res)
			res = ps->stack_a[i].place;
		i++;
	}
//	print_stack(ps);
	return (res);
}

int find_max(t_ps *ps)
{
	int i;
	int res;

	i = 0;
	res = ps->stack_a[0].place;
	while (i < ps->a_len)
	{
		if (ps->stack_a[i].place > res)
			res = ps->stack_a[i].place;
		i++;
	}
//	print_stack(ps);

    // printf("max A: %d\n", res);

	return (res);
}


void sort_5(t_ps *ps)
{
	int min;
	int max;

	min = find_min(ps);
	max = find_max(ps);
	// printf("1\n");
	// print_stack(ps);
	while (ps->a_len > 3)
	{
		if (ps->stack_a[0].place == min || ps->stack_a[0].place == max)
			pb(ps);
		else
			ra(ps);
	}

	sort_3(ps);
	// printf("2\n");
	// print_stack(ps);
	pa(ps);
	pa(ps);
	if (ps->stack_a[0].place > ps->stack_a[1].place)
		ra(ps);
	else
	{
		sa(ps);
		ra(ps);
	}
//	print_stack(ps);
//	 printf("op 5 %d\n", ps->opers);

}

int ft_abs(int i)
{
	if (i < 0)
		return (-i);
	return (i);
}
void first_move_to_b(t_ps *ps)
{
	int len;

	len = ps->a_len;
	ps->middle = ps->a_len / 2;
	while (ps->a_len > ps->middle + 2)
	{
		if (ps->stack_a[0].place < len / 4 || ps->stack_a[0].place > len - len / 4)
		{
			if (ps->stack_a[0].place < len / 4)
				pb(ps);
			else
			{
				pb(ps);
				rb(ps);
			}
		}
		else
			ra(ps);
	}
	while (ps->a_len > 5)
	{
		if (ps->stack_a[0].place != ps->middle && ps->stack_a[0].place != ps->middle + 1
				&& ps->stack_a[0].place != ps->middle - 1 
				&& ps->stack_a[0].place != ps->middle + 2
						&& ps->stack_a[0].place != ps->middle - 2
						)
		{
			if (ps->stack_a[0].place <= ps->middle)
				pb(ps);
			else
			{
				pb(ps);
				rb(ps);
			}
		}
		else
			ra(ps);
	print_stack(ps);
	}
}

void get_rotate_a(t_ps *ps, int place)
{
	int i;
	
	i = 0;
	printf("get_rot_a\n");
	printf("before rotate el.place %d ps->stack_a[0].place %d top %d bot %d\n", ps->stack_b[place].place, ps->stack_a[i].place, ps->stack_b[place].to_move_top, ps->stack_b[place].to_move_bot);

	print_stack(ps);
	if (ps->stack_b[place].to_move_top == 1)
	{
		while (ps->stack_b[place].place > ps->stack_a[i].place)
		{
			i++;
		}
		ps->stack_b[place].rotate_a = i;
		printf("now rotate up el.pl %d stapl %d elrot%d\n", ps->stack_b[place].place, ps->stack_a[i].place, ps->stack_b[place].rotate_a);
	}
	else if (ps->stack_b[place].to_move_bot == 1)
	{
	printf("testtt\n");

		while (ps->stack_b[place].place < ps->stack_a[ps->a_len - i - 1].place)
			i++;
		ps->stack_b[place].rotate_a = i;
	printf("now rot down %d st_a %d m_top %d m_bot %d el.rot %d\n", ps->stack_b[place].place, ps->stack_a[i].place, ps->stack_b[place].to_move_top, ps->stack_b[place].to_move_bot, ps->stack_b[place].rotate_a);
	}

}

void print_with_places(t_ps *ps)
{
	int i;

	i = 0;
	printf("STACK A\n");
	while (i < ps->a_len)
	{
		printf("pl %d ,  p_top %d , p_bot %d , p_min %d rot_a %d\n", 
			ps->stack_a[i].place, ps->stack_a[i].price_top, 
				ps->stack_a[i].price_bot, ps->stack_a[i].price_min, ps->stack_a[i].rotate_a);
		i++;
	}
	i = 0;
	printf("STACK B\n");
	while (i < ps->b_len)
	{
		printf("pl %d ,  p_top %d , p_bot %d , p_min %d rot_a %d\n", 
			ps->stack_b[i].place, ps->stack_b[i].price_top, 
				ps->stack_b[i].price_bot, ps->stack_b[i].price_min, ps->stack_b[i].rotate_a);
		i++;
	}
}

void get_min_path(t_ps *ps, int i)
{
//	print_with_places(ps);
	printf("get_min_price %d st_b_pl %d ps_mid %d\n", i, ps->stack_b[i].place, ps->middle);

	if (ps->stack_b[i].price_top <= ps->stack_b[i].price_bot)
	// if (ps->stack_b[i].place < ps->middle)
	// {
//	if (ps->stack_b[i].place < ps->middle)
	{
			ps->stack_b[i].price_min = ps->stack_b[i].price_top;
			ps->stack_b[i].to_move_top = 1;
			ps->stack_b[i].to_move_bot = 0;
			printf("biplace  %d st_a_0pl %d\n", ps->stack_b[i].place, ps->stack_a[0].place);
			if (ps->stack_b[i].place < ps->stack_a[0].place)
				ps->stack_b[i].rotate_a = 0;
			else
			{
				get_rotate_a(ps, i);
			printf("after get_rotate place %d rootate_a%d\n", ps->stack_b[i].place, ps->stack_b[i].rotate_a);
//				ps->stack_b[i].rotate_b = ps->stack_b[i].price_min;
				ps->stack_b[i].price_min = ps->stack_b[i].price_min + ps->stack_b[i].rotate_a;
			}
	}
//	}
	else
	{
//		printf("aaaaaaaaaaa  %d    %d\n", ps->stack_b[i].place, ps->stack_a[ps->a_len - 1].place);
		ps->stack_b[i].price_min = ps->stack_b[i].price_bot;
		ps->stack_b[i].to_move_top = 0;
		ps->stack_b[i].to_move_bot = 1;
		if (ps->stack_b[i].place > ps->stack_a[ps->a_len - 1].place)
			ps->stack_b[i].rotate_a = 0;
		else
		{
		 	get_rotate_a(ps, i);
			printf("after get_rotate %d\n", ps->stack_b[i].rotate_a);
//				ps->stack_b[i].rotate_b = ps->stack_b[i].price_min;
			ps->stack_b[i].price_min += ps->stack_b[i].rotate_a;
		}
	}

}
void get_prices(t_ps *ps)
{
	printf("get_prices\n");
	
	int i;

	i = 0;
	while (i < ps->b_len)
	{
		ps->stack_b[i].price_top = i;
		ps->stack_b[i].rotate_b = i;
		ps->stack_b[i].price_bot = ps->b_len - i - 1;
		get_min_path(ps, i);
		i++;
	}
//	print_with_places(ps);
}

void move_el_to_a(t_ps *ps, t_elem elem)
{
	printf("move_el   %d\n", elem.place);

	int i;

	printf("move_back place %d  pr_min %d rotate %d\n", elem.place, elem.price_min, elem.rotate_a);
	i = 0;
	if (elem.to_move_top)
	{
	printf("rotate_top\n");

		while (i < elem.price_min)
		{

			rb(ps);
			i++;
		}
		while (i < elem.rotate_b)
		{

			rb(ps);
			i++;
		}

		i = 0;
		while (i < elem.rotate_a)
		{
			ra(ps);
			i++;
		}
		pa(ps);
		i = 0;

		while (i < elem.rotate_a)
		{
			rra(ps);
			i++;
		}

	}
	else
	{
	printf("rotate_down\n");

		while (i < elem.rotate_b)
		{
			print_stack(ps);
			rrb(ps);
			i++;
		}
		i = 0;
		while (i < elem.rotate_a)
		{
			print_stack(ps);
			rra(ps);

			i++;
		}
		pa(ps);
		ra(ps);
		i = 0;

		while (i < elem.rotate_a)
		{
			ra(ps);
			i++;
		}

	}	

}
int get_min_el(t_ps *ps)
{
	printf("get_min_el\n");
	int i;
	int min;
	int min_place;

	i = 0;
	min = ps->stack_b[0].price_min;
	min_place = 0;
	while (i < ps->b_len)
	{
		if (ps->stack_b[i].price_min < min)
		{
			min = ps->stack_b[i].price_min;
			min_place = ps->stack_b[i].place;
		}
		i++;
	}
	printf("min_price %d   place %d\n", min, min_place);
	return (min_place);
}

void move_back_to_a(t_ps *ps)
{
	printf("move_back_main\n");
	int i;
	int min_el;

	i = 0;
	while(ps->b_len > 0)
	{
		get_prices(ps);
		min_el = get_min_el(ps);
	printf("min from min el %d\n", min_el);
	print_stack(ps);
//	sleep(1);
	while (i < ps->b_len)
	{
		if (ps->stack_b[i].place == min_el)		
			move_el_to_a(ps, ps->stack_b[i]);
		i++;
	}
	}
	print_stack(ps);
}

void main_sort(t_ps *ps)
{
	first_move_to_b(ps);
	sort_5(ps);
	move_back_to_a(ps);
	test_print(ps);
}
