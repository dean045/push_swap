/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:05:06 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/27 15:13:05 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_pos(t_list *pile_a, int val)
{
	int	x;

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

int	put_val_top(t_list **pile_a, int val, char c)
{
	int	size;
	int	pos;
	int	rot;

	if (!*pile_a || ft_lstsize(*pile_a) < 2 || (*pile_a)->content == val)
		return (0);
	size = ft_lstsize(*pile_a);
	pos = get_pos(*pile_a, val);
	rot = 0;
	while ((*pile_a)->content != val)
	{
		if (pos > (size / 2))
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

void	sort3(t_list **pile_a, t_data data)
{
	while (!is_sort(*pile_a))
	{
		if ((*pile_a)->content == data.tab[2]
			&& (*pile_a)->next->content == data.tab[0])
			(*pile_a) = rotate(pile_a, 'a');
		else if ((*pile_a)->content == data.tab[1]
			&& (*pile_a)->next->content == data.tab[2])
			(*pile_a) = rrotate(pile_a, 'a');
		else if (ft_lstlast(*pile_a)->content == data.tab[2]
			|| (*pile_a)->content == data.tab[0]
			|| (*pile_a)->next->content == data.tab[1])
		{
			swap(*pile_a, 'a');
		}
	}
}

void	sort(t_list **pile_a, t_list **pile_b, t_data data)
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
	}
	sort_suite(pile_a, pile_b, data);
}

void	sort_suite(t_list **pile_a, t_list **pile_b, t_data data)
{
	int	i;

	i = -1;
	while (++i < data.nb[2] - 1)
	{
		while (get_pos(*pile_b, get_best(*pile_a, *pile_b, data))
			> ((ft_lstsize(*pile_b) / 2)) && get_pos(*pile_a,
				get_next_sup(*pile_a, get_best(*pile_a, *pile_b, data), data))
			> ((ft_lstsize(*pile_a) / 2)))
			rrr(pile_a, pile_b);
		while (get_pos(*pile_b, get_best(*pile_a, *pile_b, data))
			<= ((ft_lstsize(*pile_b) / 2)) && get_pos(*pile_a,
				get_next_sup(*pile_a, get_best(*pile_a, *pile_b, data), data))
			<= ((ft_lstsize(*pile_a) / 2)) && get_pos(*pile_b, get_best(*pile_a,
					*pile_b, data)) && get_pos(*pile_a,
				get_next_sup(*pile_a, get_best(*pile_a, *pile_b, data), data)))
			rr(pile_a, pile_b);
		put_val_top(pile_b, get_best(*pile_a, *pile_b, data), 'b');
		put_val_top(pile_a, get_next_sup(*pile_a,
				(*pile_b)->content, data), 'a');
		push(pile_a, pile_b, 'a');
	}
	put_val_top(pile_a, data.tab[0], 'a');
}
