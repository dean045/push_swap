00000/* ************************************************************************** */
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

int get_pos(t_list	*pile_a, int val)
{
	int x;

	if (!pile_a)
		return (-1);
	x = 0;
	while (pile_a && pile_a->next && pile_a->content == val)
	{
		x++;
		pile_a = pile_a->next;
	}
	if (pile_a->content != val && x == ft_lstsize(pile_a))
		return (-1);
	return (x);
}

int get_mediane(t_list *pile_a)
{
	return (get_min(pile_a) + ((get_max(pile_a) - get_min(pile_a)) / 2));
}

void put_val_top(t_list **pile_a, int val, int *count)
{
	int		size;
	int		pos;
	t_list	*pile;

	if (!*pile_a || ft_lstsize(*pile_a) < 2)
		return ;
	size = ft_lstsize(*pile_a);
	pos = get_pos(*pile_a, val);
	pile = *pile_a;
	while (pile->content != val)
	{
		if (pos >= size / 2)
			pile = rrotate(&pile);
		else
			pile = rotate(&pile);
		(*count)++;
		printf("%i\n", *count);
	}
	*pile_a = pile;
}

void sort(t_list **pile_a, t_list **pile_b, int *count, int pivot)
{
	int	i;
	int	size;
	int min;
	int max;

	size = ft_lstsize(*pile_a);
	max = get_max(*pile_a);
	
	i = 0;

	while (i < size)
	{
		if ((*pile_a)->content != )
	}
}

void	tri(t_list **pile_a, t_list **pile_b, int *count)
{
	int	max;

	max = get_max(*pile_a);
	while (*pile_a && (!*pile_b || max != (*pile_b)->content))
	{
		put_val_top(pile_a, get_min(*pile_a), count);
		push(pile_b, pile_a);
		(*count)++;
		printf("%i\n", *count);
		print_pile(*pile_a, *pile_b);
	}
	while (*pile_b)
	{
		push(pile_a, pile_b);
		(*count)++;
		printf("%i\n", *count);
		print_pile(*pile_a, *pile_b);
	}
}

