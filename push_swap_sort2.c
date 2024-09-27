
#include "push_swap.h"

void print_stack(t_ps *ps) 
{
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
	// if (ps->stack_b[place].to_move_top == 1)
	// {
		printf("now rotate up el.pl %d stapl %d elrot %d\n", ps->stack_b[place].place, ps->stack_a[i].place, ps->stack_b[place].rotate_a);
		if (place < ps->middle)
		{
			while (place > ps->stack_a[i].place)
			{
				i++;
			}
			ps->stack_b[place].rotate_a = i;
		}
	// }
	// else if (ps->stack_b[place].to_move_bot == 1)
		else 
		{
		
		
		while (place < ps->stack_a[ps->a_len - i - 1].place)
			i++;
		ps->stack_b[place].rotate_a = i;
		}
	printf("now rot down %d st_a %d m_top %d m_bot %d el.rot %d\n", ps->stack_b[place].place, ps->stack_a[i].place, ps->stack_b[place].to_move_top, ps->stack_b[place].to_move_bot, ps->stack_b[place].rotate_a);
	printf("testtt\n");
	

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
//				get_rotate_a(ps, i);
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
//		 	get_rotate_a(ps, i);
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
//		get_min_path(ps, i);
		i++;
	}
//	print_with_places(ps);
}

void set_price1(t_ps *ps, int i)
{
    int j = 0;
    int to_b_top = i;
    int to_b_bot = ps->b_len - 1 - i;

    // Calculate price for moving element in B to the correct place in B
    if (to_b_top <= to_b_bot)
    {
        ps->stack_b[i].rotate_b = to_b_top;
        ps->stack_b[i].to_move_top = 1;
        ps->stack_b[i].price_min = to_b_top;
    }
    else
    {
        ps->stack_b[i].rotate_b = to_b_bot;
        ps->stack_b[i].to_move_top = 0;
        ps->stack_b[i].price_min = to_b_bot;
    }

    // Calculate where to insert in A
    if (ps->stack_b[i].place < ps->stack_a[0].place) 
    {
        // Element is smaller than the smallest in A, goes to bottom of A
        ps->stack_b[i].rotate_a = 0;
        ps->stack_b[i].price_min += 0;  // Already in the correct place at the bottom
    }
    else if (ps->stack_b[i].place > ps->stack_a[ps->a_len - 1].place) 
    {
        // Element is larger than the largest in A, goes to top of A
        ps->stack_b[i].rotate_a = ps->a_len;  // Rotate entire stack
        ps->stack_b[i].price_min += ps->a_len;
    }
    else 
    {
        // Element is between two elements in A, find the right place
        while (ps->stack_b[i].place > ps->stack_a[j].place)
            j++;
        
        // Calculate rotations needed for the correct insertion point
        int to_a_top = j;
        int to_a_bot = ps->a_len - j;

        if (to_a_top <= to_a_bot)
        {
            ps->stack_b[i].rotate_a = to_a_top;
            ps->stack_b[i].price_min += to_a_top;
        }
        else
        {
            ps->stack_b[i].rotate_a = to_a_bot;
            ps->stack_b[i].price_min += to_a_bot;
        }
    }

    // Optimize for simultaneous rotations
    if (ps->stack_b[i].to_move_top && ps->stack_b[i].rotate_a == ps->stack_b[i].rotate_b)
    {
        // If both stacks are moving to the top and rotate values are equal, use `rr`
        ps->stack_b[i].price_min -= ps->stack_b[i].rotate_b;  // Reduce cost
    }
    else if (!ps->stack_b[i].to_move_top && ps->stack_b[i].rotate_a == ps->stack_b[i].rotate_b)
    {
        // If both stacks are moving to the bottom and rotate values are equal, use `rrr`
        ps->stack_b[i].price_min -= ps->stack_b[i].rotate_b;  // Reduce cost
    }
}

void set_price(t_ps *ps, int i)
{
	int to_b_top;
	int to_b_bot;
	int from_a_top;
	int from_a_bot;
	int to_a_top;
	int to_a_bot;
	int j;

	to_a_bot = 0;
	to_a_top = 0;
	j = 0;
	to_b_top = i;
	to_b_bot = ps->b_len - 1 - i ;
	if (to_b_top <= to_b_bot)
	{
		ps->stack_b[i].rotate_b = i;
		ps->stack_b[i].to_move_top = 1;
		ps->stack_b[i].price_min = to_b_top; 
	}
	else
	{
		ps->stack_b[i].rotate_b = ps->b_len - 1 - i;
		ps->stack_b[i].to_move_top = 0;
		ps->stack_b[i].price_min = to_b_bot;

	}
	if (ps->stack_b[i].place < ps->stack_a[0].place)
	{
		from_a_top = ps->stack_a[0].place - ps->stack_b[i].place;
		ps->stack_b[i].price_min += from_a_top;
	}
	if(ps->stack_b[i].place > ps->stack_a[ps->a_len - 1].place)
	{
		from_a_bot = ps->stack_b[i].place - ps->stack_a[ps->a_len - 1].place;
		ps->stack_b[i].price_min += from_a_bot;
	}

	if (ps->stack_b[i].place > ps->stack_a[0].place)
	{
		j = 0;
		while (ps->stack_b[i].place > ps->stack_a[j].place)
			j++;
		to_a_top = j;
	}


	if (ps->stack_b[i].place < ps->stack_a[ps->a_len - 1].place)
	{
	printf("iiiii %d pl b %d pl a %d\n", i, ps->stack_b[i].place, ps->stack_a[0].place);
	
		j = 0;
		while (ps->stack_b[i].place < ps->stack_a[ps->a_len - 1 - j].place)
			j++;
		to_a_bot = j;
	}
		if (to_a_top < to_a_bot)
		{
			ps->stack_b[i].price_min += to_a_top;
			ps->stack_b[i].rotate_a = j;
		}
		else
		{
			ps->stack_b[i].price_min += to_a_bot;
			ps->stack_b[i].rotate_a = -j;
		}

	printf("i %d pl %d rota %d rotb %d\n", i, ps->stack_b[i].place, ps->stack_b[i].rotate_a, ps->stack_b[i].rotate_b);
}

int find_min_place(t_ps *ps)
{
	int i;
	int min_price;
	int min_pos;

	i = 0;
	min_pos = 0;
	min_price = ps->stack_b[0].price_min;
	while(i < ps->b_len)
	{
		printf("min pl %d pr %d\n", ps->stack_b[i].place, ps->stack_b[i].price_min);
		if (ps->stack_b[i].price_min < min_price)
		{
			min_price = ps->stack_b[i].price_min;
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

void order_a(t_ps *ps, t_elem elem)
{
	int i;

	i = 0;
	printf("el.place  %d el.rot_a  %d\n", elem.place, elem.rotate_a);
	if(elem.rotate_a > 0)
	{
		while(i < elem.rotate_a)
		{
			ra(ps);
			i++;
		}
		pa(ps);
		i = 0;
		while(i < elem.rotate_a)
		{
			rra(ps);
			i++;
		}
	}
	else
	{
		while(i > elem.rotate_a)
		{
			rra(ps);
			i--;
		}
		pa(ps);
		i = 0;
		while(i > elem.rotate_a)
		{
			ra(ps);
			i--;
		}
	}
}

void push_to_a(t_ps *ps)
{
	int i;
	int min_el;

	i = 0;
	min_el = find_min_place(ps);
	printf("min from min_el %d  %d\n", min_el, ps->stack_b[min_el].rotate_b);
	if (ps->stack_b[min_el].to_move_top == 1)
	{
		while (i < ps->stack_b[min_el].rotate_b)
		{
			rb(ps);
			i++;
		}
	}	
	else
	{
		while (i < ps->stack_b[min_el].rotate_b)
		{
			rrb(ps);
			i++;
		}
	}	
	order_a(ps, ps->stack_b[min_el]);

	print_stack(ps);

}
void b_print_places(t_ps *ps)
{
	int i;

	i = 0;
	while(i < ps->b_len)
	{
		printf("place %d, m_price %d, rb %d, ra %d\n", ps->stack_b[i].place, ps->stack_b[i].price_min, ps->stack_b[i].rotate_b, ps->stack_b[i].rotate_a);
		i++;
	}
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
		printf("pricemin%d\n", ps->stack_b[i].price_min);
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
	int min_place;

	i = 0;
	while(ps->b_len > 0)
	{
	// printf("min from min el %d\n", min_place);
	// print_stack(ps);
//	sleep(1);t_ps *ps

	while (i < ps->b_len)
	{
		set_price(ps, i);
		min_place = get_min_el(ps);
		if (ps->stack_b[i].place == min_place)		
			move_el_to_a(ps, ps->stack_b[i]);
		i++;
	}
	}
	print_stack(ps);
}

void put_all_to_b(t_ps *ps)
{
	while (ps->a_len > 3)
	{
		pb(ps);
	}
}
void test_for_price(t_ps *ps)
{
	int i;

	i = 0;
	b_print_places(ps);
	while (ps->b_len > 0)
	{
		i = 0;
		while(i < ps->b_len)
		{
			set_price1(ps, i);
			i++;
		}

		push_to_a(ps);
	}
	test_print(ps);
}
void main_sort(t_ps *ps)
{
	first_move_to_b(ps);
	sort_5(ps);
	put_all_to_b(ps);
	sort_3(ps);

	test_for_price(ps);
	// move_back_to_a(ps);
//	test_print(ps);
}
