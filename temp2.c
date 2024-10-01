
#include "push_swap.h"
#include <stdio.h>

void put_moves(t_ps *ps)
{
	int i;

	i = 0;
	while(i < ps->b_len)
	{
		printf("i %d place %d rbs %d rrbs %d ras %d rras %d to_top %d min_moves %d\n",
		i, ps->stack_b[i].place, ps->stack_b[i].rbs, ps->stack_b[i].rrbs, 
		ps->stack_b[i].ras, ps->stack_b[i].rras, ps->stack_b[i].to_top, ps->stack_b[i].min_moves
		);
		i++;
	}
}

void init_moves(t_ps *ps)
{
	int i;

	i = 0;
	while(i < ps->b_len)
	{
		ps->stack_b[i].rbs = -1;
		ps->stack_b[i].rrbs = -1;
		ps->stack_b[i].ras = -1;
		ps->stack_b[i].rras = -1;
		ps->stack_b[i].min_moves = 0;
		ps->stack_b[i].rbs_total = -1;
		ps->stack_b[i].rrbs_total = -1;
		ps->stack_b[i].ras_total = -1;
		ps->stack_b[i].rras_total = -1;
		i++;
	}
}

void find_rbs_rrbs(t_ps *ps)
{
	init_moves(ps);
	int i;

	i = 0;
	if (ps->b_len > 0)
	{
		while(i < ps->b_len)
		{
			if (ps->stack_b[i].place < ps->middle)
				ps->stack_b[i].to_top = 1;
			else
				ps->stack_b[i].to_top = 0;

			if (i <= ps->b_len / 2)
				ps->stack_b[i].rbs = i;
			else
				ps->stack_b[i].rrbs = ps->b_len - 1 - i;
			//printf("ilen %d rbs %d rrbs %d\n", i, ps->stack_b[i].rbs, ps->stack_b[i].rbs);
			ps->stack_b[i].rbs_total = ps->stack_b[i].rbs;
			ps->stack_b[i].rrbs_total = ps->stack_b[i].rrbs;
			i++;
		}
	}
}

void find_ras_rras(t_ps *ps)
{
	int i;
	int j;

	i = 0;
	while(i < ps->b_len)
	{
		if (ps->stack_b[i].place < ps->stack_a[0].place)
			ps->stack_b[i].ras = 0;
		else
		{
			j = 0;
			while(j < ps->a_len && ps->stack_b[i].place > ps->stack_a[j].place)
				j++;
			ps->stack_b[i].ras = j;
		}
		if (ps->stack_b[i].place > ps->stack_a[ps->a_len - 1].place)
			ps->stack_b[i].rras = 0;
		else
		{
			j = 0;
			while(j < ps->a_len && ps->stack_b[i].place < ps->stack_a[ps->a_len - 1 - j].place)
				j++;
			ps->stack_b[i].rras = j;
		}
			ps->stack_b[i].ras_total = ps->stack_b[i].ras;
			ps->stack_b[i].rras_total = ps->stack_b[i].rras;

		i++;
	}
}

int ft_abs(int i)
{
	if (i < 0)
		return (i * -1);
	return (i);
}

void	set_move(t_ps *ps, int i)
{
	ps->ras = ps->stack_b[i].ras;
	ps->rbs = ps->stack_b[i].rbs;
	ps->rras = ps->stack_b[i].rras;
	ps->rrbs = ps->stack_b[i].rrbs;
	ps->ras_total = ps->stack_b[i].ras_total;
	ps->rras_total = ps->stack_b[i].rras_total;
}

void find_min_moves(t_ps *ps)
{
	int i;

	i = 0;
	init_moves(ps);
	find_rbs_rrbs(ps);
	find_ras_rras(ps);
	while(i < ps->b_len)
	{
//		printf("abs %d %d\n", ps->stack_b[i].place, ft_abs(ps->stack_b[i].place - ps->a_len / 2));
		if (ps->stack_b[i].rbs >= 0)
			ps->stack_b[i].min_moves += ps->stack_b[i].rbs + 1;
		if (ps->stack_b[i].rrbs >= 0)
			ps->stack_b[i].min_moves += ps->stack_b[i].rrbs + 1;
		if (ps->stack_b[i].to_top == 1)
		{
			ps->stack_b[i].min_moves += ps->stack_b[i].ras;
			ps->stack_b[i].min_moves += (ft_abs(ps->stack_b[i].place - ps->middle));
		}
		if (ps->stack_b[i].to_top == 0)
		{
			ps->stack_b[i].min_moves += ps->stack_b[i].rras;
			ps->stack_b[i].min_moves += ft_abs(ps->stack_b[i].place - ps->middle);
		}
		i++;
	}
}

int find_min_el(t_ps *ps)
{
	int i;
	int min_el;
	int min_moves;

	i = 0;
	min_el = 0;
	find_min_moves(ps);
	min_moves = ps->stack_b[0].min_moves;

	while(i < ps->b_len)
	{
		if (ps->stack_b[i].min_moves < min_moves)
		{
			min_moves = ps->stack_b[i].min_moves;
			min_el = i;
		}
		i++;
	}
	// put_moves(ps);
	// printf("min_el %d \n", min_el);
	return (min_el);
}

void prepare_a(t_ps *ps, int el_index)
{
	set_move(ps, el_index);
	int i;
//	int new_index;
//	int change;
//	printf("prepare el %d ras %d rras %d rbs %d rrbs %d top %d bot \n", ps->stack_b[el_index].place, ps->stack_b[el_index].ras, ps->stack_b[el_index].rras, ps->stack_b[el_index].rbs, ps->stack_b[el_index].rrbs, ps->stack_b[el_index].to_top);
	// new_index = el_index;
	i = 0;

	if(ps->stack_b[el_index].to_top == 1)
	{
		while(ps->ras > 0 && ps->rbs > 0)
		{
			rr(ps);
			ps->ras--;
			ps->rbs--;
		}
		while(i < ps->ras)
		{
			ra(ps);
			ps->ras--;
		}
	}
	else
	{
		while(ps->rras > 0 && ps->rrbs > 0)
		{
			rrr(ps);
			ps->rras--;
			ps->rrbs--;
		}
		while(i < ps->rras)
		{
			rra(ps);
			ps->rras--;
		}
	}
//	change = 0;
// 	if(ps->stack_b[new_index].to_top == 1)
// 	{

// 		while(i < ps->stack_b[new_index].ras && i < ps->stack_b[new_index].rbs)
// 		{
// printf("Perfo rr: ras = %d, rbs = %d\n", ps->stack_b[new_index].ras, ps->stack_b[new_index].rbs);

// 				rr(ps);
// 			i++;
// 			new_index = (new_index - 1 + ps->b_len) % ps->b_len;
// 			ps->stack_b[new_index].rbs--;
// 			ps->stack_b[new_index].ras--;
// //			change--;
// printf("after rr: ras = %d, rbs = %d\n", ps->stack_b[new_index].ras, ps->stack_b[new_index].rbs);
// 		}
// //		i = 0;
// 		while(i < ps->stack_b[new_index].ras)
// 		{
// //printf("Performing ra: ras = %d, rbs = %d\n", ps->stack_b[new_index].ras, ps->stack_b[new_index].rbs);
// 				ra(ps);
// 			i++;
// //			new_index--;
// 		}

// 	}
// 	else
// 	{
// 		while(i < ps->stack_b[new_index].rras && i < ps->stack_b[new_index].rrbs)
// 		{
// printf("Perfo rrr: ras = %d, rbs = %d\n", ps->stack_b[new_index].rras, ps->stack_b[new_index].rrbs);

// 				rrr(ps);
// 			i++;

// 			new_index = (new_index + 1);
// 			ps->stack_b[new_index].rrbs--;
// 			ps->stack_b[new_index].rras--;
// printf("after rr: ras = %d, rbs = %d\n", ps->stack_b[new_index].rras, ps->stack_b[new_index].rrbs);
// //			change++;
// 		}

// 		while(i < ps->stack_b[el_index].rras)
// 		{
// 				rra(ps);
// 			i++;
// 		}
	// }
//	return(change);
}

void restore_a(t_ps *ps)
{
	int i;
	int ras;
	int rras;

	ras = ps->stack_a[0].ras_total;
	rras = ps->stack_a[0].rras_total;
	printf("restore el %d ras %d rras %d top %d bot \n", ps->stack_a[0].place, ps->stack_a[0].ras, ps->stack_a[0].rras, ps->stack_a[0].to_top);

	i = 0;
	if(ps->stack_a[0].to_top == 1)
	{
		while(i < ras)
		{
				rra(ps);
			i++;
		}
	}
	else
//	if(ps->stack_a[0].to_bot == 1)
	{
		if(ps->stack_a[0].place > ps->middle)
			ra(ps);
//		printf("hmm %d\n", ras);
		while(i < rras)
		{
				ra(ps);
			i++;
		}
	}
//	print_stack(ps);
}

void put_el_to_a(t_ps *ps, int el_index)
{
//	int i;

//	int rbs;
//	int rrbs;
//	int index;

// 	rbs = ps->rbs; 
// 	rrbs = ps->rrbs; 
// //	index = el_index;
//	printf("index %d %d\n", index, el_index);
//	printf("begin put el %d ras %d rras %d rbs %d rrbs %d \n", ps->stack_b[index].place, ps->stack_b[index].ras, ps->stack_b[index].rras, ps->stack_b[index].rbs, ps->stack_b[index].rrbs);

	prepare_a(ps, el_index);
//	printf("after put el %d ras %d rras %d rbs %d rrbs %d \n", ps->stack_b[index].place, ps->stack_b[index].ras, ps->stack_b[index].rras, ps->stack_b[index].rbs, ps->stack_b[index].rrbs);
//	i = 0;
	// if (ps->stack_b[index].rbs > 0)
	// {
		while (ps->rbs > 0)
		{
// 			if (ps->stack_b[el_index].ras > 0)
// 			{
// //				rr(ps);
// 				ps->stack_b[el_index].ras--;
// 			}
// 			else
				rb(ps);
			ps->rbs--;
//			index--;
		// }
	}
	// else if (ps->stack_b[index].rrbs >= 0)
	// {
		while (ps->rrbs > 0)
		{
			// if (ps->stack_b[el_index].ras > 0)
			// {
			// 	rrr(ps);
			// 	ps->stack_b[el_index].ras--;
			// }
			// else
				rrb(ps);
			ps->rrbs--;
//			index++;

		}
	// }
//	rrb(ps);
	// if (ps->stack_b[el_index].ras < ps->stack_b[el_index].rras)
	// else
	// 	prepare_a(ps, el_index, ps->stack_b[el_index].rras);

	pa(ps);
//	printf("puted el %d ras %d rras%d \n", ps->stack_a[0].place, ps->stack_a[0].ras, ps->stack_a[0].rras);
//	print_stack(ps);
	restore_a(ps);
}


void new_sort(t_ps *ps)
{
	int min_el;

//	assign_place(ps);
	first_move_to_b(ps);
	sort_5(ps);
	// put_all_to_b(ps);
	// sort_3(ps);
while(ps->b_len > 0)
{
	min_el = find_min_el(ps);
//	printf("from min %d\n", min_el);
	put_el_to_a(ps, min_el);
}
//	print_stack(ps);

	// move_back_to_a(ps);
//	test_print(ps);
}

