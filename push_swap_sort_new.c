
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
	ps->ras_total = ps->stack_b[i].ras;
	ps->rras_total = ps->stack_b[i].rras;
	if (ps->stack_b[i].place > ps->middle)
		ps->to_top = 0;
	else
		ps->to_top = 1;
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
			ps->stack_b[i].min_moves += ps->stack_b[i].rbs + 2;
		if (ps->stack_b[i].rrbs >= 0)
			ps->stack_b[i].min_moves += ps->stack_b[i].rrbs + 2;
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
	//  put_moves(ps);
//printf("min_el %d \n", min_el);
	//  print_stack(ps);
	return (min_el);
}

void prepare_a(t_ps *ps)
{
	// int i;
	// i = 0;

	if(ps->to_top == 1)
	{
		while(ps->ras > 0 && ps->rbs > 0)
		{
			rr(ps);
			ps->ras--;
			ps->rbs--;
		}
		while(ps->ras > 0)
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
		while(ps->rras > 0)
		{
			rra(ps);
			ps->rras--;
		}
	}
}

//		if (ps->stack_b[0].place <)
	// printf("pl b0 %d  pl a0 %d\n", ps->stack_b[0].place, ps->stack_a[ps->a_len - 1].place);
	// print_stack(ps);
		// while(ps->stack_b[0].place == ps->stack_a[0].place - 1)
		// 	pa(ps);
		// while(ps->ras_total > 0 && ps->rrbs > 0)
		// {
		// 		rrr(ps);
		// 	ps->ras_total--;
		// 	ps->rrbs--;
		// }

		// while(ps->stack_b[0].place == ps->stack_a[ps->a_len - 1].place + 1)
		// {
		// 	pa(ps);
		// 	ra(ps);
		// }
		// while(ps->rras_total > 0 && ps->rbs > 0)
		// {
		// 		rr(ps);
		// 	ps->rras_total--;
		// 	ps->rrbs--;
		// }
void restore_a(t_ps *ps)
{
	if(ps->to_top == 1)
	{
			if (ps->b_len > 1)
			{
				if(ps->stack_b[0].place == ps->stack_a[0].place - 1)
				{
					pa(ps);
					
				}
			}
		while(ps->ras_total > 0 && ps->rrbs > 0)
		{
				rrr(ps);
			ps->ras_total--;
			ps->rrbs--;
		}
		while(ps->ras_total > 0)
		{
				rra(ps);
			ps->ras_total--;
		}
	}
	else
	{
		ra(ps);
		// if (ps->b_len > 1)
		// {
			// while(ps->stack_b[0].place == ps->stack_a[ps->a_len - 1].place + 1)
			// {
			// 	pa(ps);
			// 	ra(ps);
			// }
		// }
		while(ps->rras_total > 0 && ps->rbs > 0)
		{
			rr(ps);
			ps->rras_total--;
			ps->rbs--;
		}
		while(ps->rras_total > 0)
		{
			ra(ps);
			ps->rras_total--;
		}
	}
}


void put_el_to_a(t_ps *ps)
{
	int min_el;
	// int rest_ras;
	// int rest_rras;
	// int rest_to_top;
	// int need_to_rrb;
	
	// need_to_rrb = 0;
	// rest_ras = ps->ras_total;
	// rest_rras = ps->rras_total;
	// rest_to_top = ps->to_top;
if(ps->first_move == 0)
		restore_a(ps);
	min_el = find_min_el(ps);
	set_move(ps, min_el);
//	printf("ras %d rras %d rbs %d rrbs %d ras_tot %d rras_tot %d to_top %d\n", ps->ras, ps->rras, ps->rbs, ps->rrbs, ps->ras_total, ps->rras_total, ps->to_top);
// 		if (ps->rrbs > 0)
// 			need_to_rrb = 1;
// 	if(ps->first_move == 0)
//  	{
// 		if(rest_to_top == 1)
// 		{
// //	printf("rest ras %d rest rras %d rbs %d rrbs %d \n", rest_ras, rest_rras, ps->rbs, ps->rrbs);
// 		if (rest_ras > rest_rras)
// 		{
// 			while(rest_rras > 0 && ps->rbs > 0)
// 			{
// 				rr(ps);
// 				rest_rras--;
// 				ps->rbs--;
// 			}
// 			while(rest_rras > 0)
// 			{
// 				ra(ps);
// 				rest_rras--;
// 			}
// 		}
// 		}
// 		else
// 		{
// 			ra(ps);
// 		if (rest_ras < rest_rras)
// 		{

// 			while(rest_ras > 0 && ps->rrbs > 0)
// 			{
// 					rrr(ps);
// 				rest_ras--;
// 				ps->rrbs--;
// 			}
// 			while(rest_ras > 0)
// 			{
// 				rra(ps);
// 				rest_ras--;
// 			}
// 		}
// 		}
// 	}

	// printf("index %d place %d\n", el_index, ps->stack_b[el_index].place);
	prepare_a(ps);
	while (ps->rbs > 0)
	{
		rb(ps);
		ps->rbs--;
	}
	while (ps->rrbs >= 0)
	{
		rrb(ps);
		ps->rrbs--;
	}
	// if (need_to_rrb == 1)
	// 	rrb(ps);
	pa(ps);
//	restore_a(ps);
	// if (ps->to_top == 0)
	// 	ra(ps);
	ps->first_move = 0;
}


void new_sort(t_ps *ps)
{
//	int min_el;

//	assign_place(ps);
	sort_small(ps);
//	sort_3(ps);
// 	ps->first_move = 1;
// 	// put_all_to_b(ps);
// 	// sort_3(ps);
// while(ps->b_len > 0)
// {
	
// //	printf("from min %d\n", min_el);
// 	put_el_to_a(ps);
// }
// 		restore_a(ps);

//	print_stack(ps);

	// move_back_to_a(ps);
//	test_print(ps);
}

