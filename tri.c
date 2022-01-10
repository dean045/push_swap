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
		if (pos >= (size/ 2))
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

void sort_suite(t_list **pile_a, t_list **pile_b, t_data data, int nbPivot)
{
	int size;
	int x;
	int rot;
	int i = 0;

	x = 0;
	size = ft_lstsize(*pile_a);
	while (++x <= nbPivot)
	{
		while ((x == nbPivot + 1 || (i < data.nb[nbPivot] - data.nb[nbPivot - x] - x)))
		{
			rot = put_val_top(pile_b, data.tab[data.nb[nbPivot] - i - x]);
			if ((*pile_b))
				push(pile_a, pile_b, 'a');
			else
				break;
			i++;
		}
		if (x < nbPivot + 1)
			rrotate(pile_a, 'a');
	}
}

void sort(t_list **pile_a, t_list **pile_b, t_data data, int nbPivot)
{
	int x;
	int	i;
	t_data data_temp;

	x = -1;
	i = 0;
	while (++x < nbPivot + 1)
	{
		while (i < data.nb[x] - x)
		{
			printf("nbpivot = %i, (*pile_a)->content = %i, data.value[x] = %i, is data %i \n", nbPivot, (*pile_a)->content, data.value[x], is_data((*pile_a)->content, nbPivot, data));
			//printf("data nbx = %i // x = %i // i = %i \n", data.nb[x], x, i);
			if (((x == nbPivot) || (*pile_a)->content < data.value[x]) &&
					is_data((*pile_a)->content, nbPivot, data) == 0)
			{
				i++;
				push(pile_b, pile_a, 'b');
				if ((*pile_b)->next && ((*pile_b)->content < (*pile_b)->next->content))
					swap(*pile_b, 'b');
			}
			else
				rotate(pile_a, 'a');
		}
	}
	print_pile(*pile_a, *pile_b);
	// x = ft_lstsize(*pile_a);
	data_temp.tab = put_in_tab(*pile_a, ft_lstsize(*pile_a));
	data_temp = get_data(data_temp.tab, nbPivot, 5);
	sort_five(pile_a, pile_b, data_temp);
	/*if (!is_sort(*pile_a) && nbPivot == 3)
		sort3(pile_a, data_temp);*/
	print_pile(*pile_a, *pile_b);
	sort_suite(pile_a, pile_b, data, nbPivot);
	//
	
}
