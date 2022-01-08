/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:05:06 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/26 17:25:43 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int get_pos(t_list *pile_a, int val)
{
	int x;

	if (!pile_a)
		return (-1);
	x = 0;
	while (pile_a && pile_a->next && pile_a->content != val)
	{
		x++;
		pile_a = pile_a->next;
	}
	if (pile_a->content != val && x == ft_lstsize(pile_a))
		return (-1);
	return (x);
}

int put_val_top(t_list **pile_a, int val)
{
	int size;
	int pos;
	int rot;

	if (!*pile_a || ft_lstsize(*pile_a) < 2)
		return (0);
	size = ft_lstsize(*pile_a);
	pos = get_pos(*pile_a, val);
	rot = 0;
	while ((*pile_a)->content != val)
	{
		if (pos >= (size / 2) - 1)
		{
			rrotate(pile_a, 'a');
			rot--;
		}
		else
		{
			rotate(pile_a, 'a');
			rot++;
		}
	}
	return (rot);
}

void sort3(t_list **pile_a, t_data data)
{
	while (!is_sort(*pile_a))
	{
		if ((*pile_a)->content == data.value[2] && (*pile_a)->next->content == data.value[0])
			(*pile_a) = rotate(pile_a, 'a');
		else if ((*pile_a)->content == data.value[1] && (*pile_a)->next->content == data.value[2])
			(*pile_a) = rrotate(pile_a, 'a');
		else if (ft_lstlast(*pile_a)->content == data.value[2] || (*pile_a)->content == data.value[0] || (*pile_a)->next->content == data.value[1])
		{
			swap(*pile_a, 'a');
		}
	}
}

void sort_suite(t_list **pile_a, t_list **pile_b, t_data data)
{
	int size;
	int rot;
	int i = 0;

	rot = 0;
	size = ft_lstsize(*pile_a);

	while (i < data.nb[3] - data.nb[2] - 1)
	{
		printf("%i\n", data.tab[data.nb[2] + i + 1]);
		//put_val_top(pile_b, data.tab[data.nb[2] + i + 1]);
		if ((*pile_b)->content > data.value[2])
		{
			if ((*pile_b)->content < (*pile_b)->next->content)
					swap(*pile_b, 'b');
			push(pile_a, pile_b, 'a');
			if ((*pile_a)->content > (*pile_a)->next->content)
					swap(*pile_a, 'a');
			i++;
		}
		else
			rotate(pile_b, 'b');
			//printf("test\n");
			//print_pile(*pile_a, *pile_b);
	}
	rrotate(pile_a, 'a');
	//printf("%i %i %i %i\n", data.nb[0], data.nb[1], data.nb[2], data.nb[3]);
	
	while (i < data.nb[3] - data.nb[1] - 2)
	{
		if ((*pile_b)->content < data.value[2] && (*pile_b)->content > data.value[1])
		{
			if ((*pile_b)->content < (*pile_b)->next->content)
					swap(*pile_b, 'b');
			push(pile_a, pile_b, 'a');
			if ((*pile_a)->content > (*pile_a)->next->content)
					swap(*pile_a, 'a');
			i++;
		}
		else
			rotate(pile_b, 'b');
			//print_pile(*pile_a, *pile_b);
	}
	rrotate(pile_a, 'a');

	while (i < data.nb[3] - data.nb[0] - 3)
	{
		if ((*pile_b)->content < data.value[1] && (*pile_b)->content > data.value[0])
		{
			if ((*pile_b)->content < (*pile_b)->next->content)
					swap(*pile_b, 'b');
			push(pile_a, pile_b, 'a');
			if ((*pile_a)->content > (*pile_a)->next->content)
					swap(*pile_a, 'a');
			i++;
		}
		else
			rotate(pile_b, 'b');
			//print_pile(*pile_a, *pile_b);
	}
	//rrotate(pile_a, 'a');
	
	while (*pile_b)
	{
		if ((*pile_b)->content < data.value[0])
		{
			if ((*pile_b)->next &&(*pile_b)->content < (*pile_b)->next->content)
					swap(*pile_b, 'b');
			push(pile_a, pile_b, 'a');
			if ( (*pile_a)->content > (*pile_a)->next->content)
					swap(*pile_a, 'a');
			i++;
		}
		else
			rotate(pile_b, 'b');
		//print_pile(*pile_a, *pile_b);
	}
	if (!is_sort(*pile_a))
	sort(pile_a, pile_b, data);
	//printf("%i %i %i %i\n", data.nb[0], data.nb[1], data.nb[2], data.nb[3]);
}

void sort(t_list **pile_a, t_list **pile_b, t_data data)
{
	int x;
	int	i;

	x = -1;
	i = 0;
	while (++x < 4)
	{
		while (i < data.nb[x] - x)
		{
			//if (x < 3)
			//printf("value = %i // i = %i // x = %i / nb =  %i\n", data.value[x] , i, x, data.nb[x] );
			if (((x == 3) || (*pile_a)->content < data.value[x]) && (*pile_a)->content != data.value[0] && (*pile_a)->content != data.value[1] && (*pile_a)->content != data.value[2])
			{
				i++;
				push(pile_b, pile_a, 'b');
				//printf("test\n");
				if ((*pile_b)->next && ((*pile_b)->content < (*pile_b)->next->content))
					swap(*pile_b, 'b');
			}
			else
				rotate(pile_a, 'a');
			//print_pile(*pile_a, *pile_b);
		}
	}
	sort3(pile_a, data);
	rotate(pile_a, 'a');
	rotate(pile_a, 'a');
	sort_suite(pile_a, pile_b, data);
}
