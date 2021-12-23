/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:05:06 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/23 12:18:56 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

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
		if (pos <= size / 2)
			pile = rrotate(*pile_a);
		else
			pile = rotate(*pile_a);
		*count++;
	}
	*pile_a = pile;
}

void	tri(t_list *pile_a, t_list *pile_b, int *count)
{
	int	max;

	max = get_max(pile_a);
	while (pile_a && (!pile_b || max != (pile_b)->content))
	{
		put_val_top(&pile_a, get_min(pile_a), count);
		pile_a = push(&pile_b, pile_a);
		*count++;
	}
	while (pile_b)
	{
		pile_b = push(&pile_a, pile_b);
		*count++;
	}
}
