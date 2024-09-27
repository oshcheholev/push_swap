
#include "push_swap.h"
#include <stdio.h>

void put_moves(t_ps *ps)
{
	int i;

	i = 0;
	while(i < ps->b_len)
	{
		printf("i %d place %d rbs %d rrbs %d ras %d rras %d min_moves %d\n",
		i, ps->stack_b[i].value, ps->stack_b[i].rbs, ps->stack_b[i].rrbs, 
		ps->stack_b[i].ras, ps->stack_b[i].rras, ps->stack_b[i].min_moves
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
		i++;
	}
}

void find_rbs_rrbs(t_ps *ps)
{
	int i;

	i = 0;
	while(i < ps->b_len)
	{
		if (i <= ps->b_len / 2)
			ps->stack_b[i].rbs = i;
		else
			ps->stack_b[i].rrbs = ps->b_len - 1 - i;
		i++;
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
		if (ps->stack_b[i].place > ps->stack_a[0].place)
			ps->stack_b[i].rras = 0;
		else
		{
			j = 0;
			while(j < ps->a_len && ps->stack_b[i].place < ps->stack_a[j].place)
				j++;
			ps->stack_b[i].rras = j;
		}
		i++;
	}
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
		if (ps->stack_b[i].rbs >= 0)
			ps->stack_b[i].min_moves += ps->stack_b[i].rbs;
		if (ps->stack_b[i].rrbs >= 0)
			ps->stack_b[i].min_moves += ps->stack_b[i].rrbs;
		if (ps->stack_b[i].ras >= 0)
			ps->stack_b[i].min_moves += ps->stack_b[i].ras;
		if (ps->stack_b[i].rras >= 0)
			ps->stack_b[i].min_moves += ps->stack_b[i].rras;
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
	put_moves(ps);
	printf("min_el %d \n", min_el);
	return (min_el);
}

void prepare_a(t_ps *ps, int el_index, int bot)
{
	int i;

	i = 0;
	if(bot == 0)
	{
		while(i < ps->stack_b[el_index].ras)
		{
				ra(ps);
			i++;
		}
	}
	else
	{
		while(i < ps->stack_b[el_index].rras)
		{
				rra(ps);
			i++;
		}
	}
}

void restore_a(t_ps *ps)
{
	int i;
	int ras;
	int rras;

	ras = ps->stack_a[0].ras;
	rras = ps->stack_a[0].rras;

	i = 0;
	if(ras > 0)
	{
		while(i < ras)
		{
				rra(ps);
			i++;
		}
	}
	else
	{
		while(i < rras)
		{
				ra(ps);
			i++;
		}
	}
}

void put_el_to_a(t_ps *ps, int el_index)
{
	int i;

	i = 0;
	if (ps->stack_b[el_index].rbs > 0)
	{
		while (i < el_index)
		{
			rb(ps);
			i++;
		}
		prepare_a(ps, el_index, 0);
	}
	else if (ps->stack_b[el_index].rrbs > 0)
	{
		while (i < ps->stack_b[el_index].rrbs)
		{
			rrb(ps);
			i++;
		}
		prepare_a(ps, el_index, 1);
	}
	pa(ps);
	printf("puted el %d %d %d ", ps->stack_a[0].place, ps->stack_a[0].ras, ps->stack_a[0].rras);
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
	put_el_to_a(ps, min_el);
}
	print_stack(ps);

	// move_back_to_a(ps);
//	test_print(ps);
}

