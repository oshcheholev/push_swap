/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oshcheho <oshcheho@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:10:56 by oshcheho          #+#    #+#             */
/*   Updated: 2024/10/03 17:30:31 by oshcheho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_temp_arr(t_ps *ps)
{
	int	i;
	int	*res;

	i = 0;
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

int	*temp_sort_arr(t_ps *ps)
{
	int	i;
	int	j;
	int	*res;
	int	temp;

	res = create_temp_arr(ps);
	if (!res)
		return (free(res), NULL);
	i = ps->a_len - 1;
	while (i > 0)
	{
		j = 0;
		while (j < i)
		{
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
	return (res);
}

void	assign_place(t_ps *ps)
{
	int	i;
	int	j;
	int	*arr;

	i = 0;
	j = 0;
	arr = temp_sort_arr(ps);
	if (!arr)
		return (free(arr));
	while (i < ps->a_len)
	{
		while (j < ps->a_len)
		{
			if (ps->stack_a[j].value == arr[i])
				ps->stack_a[j].place = i;
			j++;
		}
		j = 0;
		i++;
	}
	free(arr);
}

void	move_half_to_b(t_ps *ps)
{
	int	len;

	len = ps->a_len;
	if ((ps->a_len % 2) == 0)
		ps->middle = ps->a_len / 2;
	else
		ps->middle = ps->a_len / 2 + 1;
	while (ps->a_len > ps->middle + 2)
	{
		if (ps->stack_a[0].place < len / 4
			|| ps->stack_a[0].place > len - len / 4)
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
}

void	first_move_to_b(t_ps *ps)
{
	move_half_to_b(ps);
	while (ps->a_len > 5)
	{
		if (ps->stack_a[0].place != ps->middle
			&& ps->stack_a[0].place != ps->middle + 1
			&& ps->stack_a[0].place != ps->middle - 1
			&& ps->stack_a[0].place != ps->middle + 2
			&& ps->stack_a[0].place != ps->middle - 2)
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
	}
}
