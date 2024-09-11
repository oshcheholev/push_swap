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
	while(k < len + 1)
	{
		price = ps->stack_a[k].place - i + k;
		// printf ("k  %d  price %d\n", k, price);
		ps->stack_a[k].price_top = price;
		price = ps->stack_a[ps->a_len - k].place - i + k + 1;
		// printf ("k  %d  pricebot %d\n", k, price);
		ps->stack_a[ps->a_len -1 - k].price_bot = price;
//		printf ("k  %d  price \n", k);
		k++;
	}
	k = 0;

	printf ("ksssssssssssss  %d  price \n", ps->stack_a[4].price_top);

	// while (k < ps->a_len)
	// {
	// 	printf ("%d  %d val  %d  price_top  %d   price_bot  %d\n", k, ps->a_len, ps->stack_a[k].value, ps->stack_a[k].price_top, ps->stack_a[k].price_bot);
	// 	k++;
	// }

	// i = 0;
	 
	if (ps->a_len == 2)
	{
//		printf("opers %d\n", i);
		return ;
	}
	
	j = ps->a_len - 1;

	// if (ps->stack_a[0].place > ps->stack_a[1].place)
	// 	sa(ps);
	// if (ps->stack_a[0].place > ps->stack_a[j].place)
	// 	rra(ps);
	main_sort(ps, i);
	i++;
	find_element(ps, i);
}


void	main_sort(t_ps *ps, int i, int top_or_bot)
{
	int j;
	int k;
	
	k = 0;
		j = 0;
		while(k < ps->a_len)
		{
			if (ps->stack_a[k].place == i)
			{
				while (j < k)
				{
					ra(ps);
					j++;
				}
				pb(ps);
			}
			k++;
		}
//		i++;
}