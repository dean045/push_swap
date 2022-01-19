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
	while (pile_a && pile_a->content != val)
	{
		x++;
		pile_a = pile_a->next;
	}
	if (!pile_a)
		return (-1);
	return (x);
}

int put_val_top(t_list **pile_a, int val, char c)
{
	int size;
	int pos;
	int rot;

	if (!*pile_a || ft_lstsize(*pile_a) < 2 || (*pile_a)->content == val)
		return (0);
	size = ft_lstsize(*pile_a);
	pos = get_pos(*pile_a, val);
	rot = 0;
	while ((*pile_a)->content != val)
	{
		if (pos > (size/ 2))
		{
			rrotate(pile_a, c);
			rot--;
		}
		else
		{
			rotate(pile_a, c);
			rot++;
		}
	}
	return (rot);
}

void sort3(t_list **pile_a, t_data data)
{
	while (!is_sort(*pile_a))
	{
		if ((*pile_a)->content == data.tab[2] && (*pile_a)->next->content == data.tab[0])
			(*pile_a) = rotate(pile_a, 'a');
		else if ((*pile_a)->content == data.tab[1] && (*pile_a)->next->content == data.tab[2])
			(*pile_a) = rrotate(pile_a, 'a');
		else if (ft_lstlast(*pile_a)->content == data.tab[2] || (*pile_a)->content == data.tab[0] || (*pile_a)->next->content == data.tab[1])
		{
			swap(*pile_a, 'a');
		}
	}
}

void sort(t_list **pile_a, t_list **pile_b, t_data data, int nbPivot)
{
	int	i;

	i = 0;
	while (i < data.nb[2] - 1)
	{
		if ((*pile_a)->content == data.value[1])
			rotate(pile_a, 'a');
		else
		{
			push(pile_b, pile_a, 'b');
			if ((*pile_b)->content < data.value[0])
				rotate(pile_b, 'b');
			i++;
		}
		
		/*if (i < data.nb[0])
		{
			while ((*pile_a)->content >= data.value[0])
				rotate(pile_a, 'a');
			if ((*pile_a)->content < data.value[0])
				push(pile_b, pile_a, 'b');
		}
		else
		{
			if ((*pile_a)->content == data.value[1])
				rotate(pile_a, 'a');
			else
				push(pile_b, pile_a, 'b');
		}*/
	}
	print_pile(*pile_a, *pile_b);
	sort_suite(pile_a, pile_b, data, 2);
}

void sort_suite(t_list **pile_a, t_list **pile_b, t_data data, int nbPivot)
{
	int	i;
	int a;
	int b;
	int x;

	i = -1;

	while (++i < data.nb[2] - 2)
	{
		b = get_best(*pile_a, *pile_b, data);
		a = get_next_sup(*pile_a, b, 2, data);
		if (get_pos(*pile_b, b) > ((ft_lstsize(*pile_b) - 1) / 2)
			&& get_pos(*pile_a, a) > ((ft_lstsize(*pile_a)- 1 ) / 2))
			{
				while (b != (*pile_b)->content && a != (*pile_a)->content)
					rrr(pile_a, pile_b);
			}
		else if (get_pos(*pile_b, b) <= ((ft_lstsize(*pile_b) - 1) / 2) 
		&&  get_pos(*pile_a, a) <= ((ft_lstsize(*pile_a)- 1 ) / 2))
		{
			while (b != (*pile_b)->content && a != (*pile_a)->content)
				rr(pile_a, pile_b);
		}
		put_val_top(pile_b, b, 'b');
		put_val_top(pile_a, a, 'a');
		push(pile_a, pile_b, 'a');
	}
	x = get_pos(*pile_a, data.tab[0]);
	while ((*pile_a)->content != data.tab[0])
	{
		if (x > ((data.nb[2] - 1) / 2))
			rrotate(pile_a, 'a');
		else
			rotate(pile_a, 'a');
	}
}

int get_best(t_list *pile_a, t_list *pile_b, t_data data)
{
    int op;
	int tmp;
	int	i;
	int	size;
	int val;
	t_list  *temp;

	i = 0;
	if (!pile_b)
		return (0);
	size = ft_lstsize(pile_b);
	op = size * 2;
	val = (pile_b)->content;
	temp = pile_b;
	while (temp && op)
	{
		tmp = get_pos(pile_a, get_next_sup(pile_a, (temp)->content, 2, data));
		if (tmp > ((ft_lstsize(pile_a) -1) / 2))
			tmp = ft_lstsize(pile_a) - tmp;
		if (i > ((size -1) / 2))
			tmp += size - i;
		else
			tmp += i;
		if (tmp < op)
		{
			val = (temp)->content;
			if (i <= (size -1) / 2)
				op = tmp;
			else
				op = size - tmp;
		}
		temp = temp->next;
		i++;
	}
	return (val);
}
