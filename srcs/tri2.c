/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:05:06 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/27 14:41:29 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	reset_rot(t_list **pile_a, int rot, int val, int size)
{
	while (rot && (*pile_a)->content >= val)
	{
		if (rot >= (size / 2))
		{
			rrotate(pile_a, 'a');
		}
		else
		{
			rotate(pile_a, 'a');
		}
	}
}

int	is_data(int val, int nbPivot, t_data data)
{
	int	i;

	i = -1;
	while (++i < nbPivot)
	{
		if (val == data.value[i])
			return (1);
	}
	return (0);
}

void	sort_five(t_list **pile_a, t_list **pile_b, t_data data)
{
	t_data	data_temp;

	put_val_top(pile_a, data.tab[0], 'a');
	push(pile_b, pile_a, 'b');
	put_val_top(pile_a, data.tab[1], 'a');
	push(pile_b, pile_a, 'b');
	data_temp.tab = put_tab(*pile_a, 3);
	sort3(pile_a, data_temp);
	push(pile_a, pile_b, 'a');
	push(pile_a, pile_b, 'a');
	free(data_temp.tab);
}

int	get_next_sup(t_list *pile_a, int val, t_data data)
{
	int		size;
	int		result;
	t_list	*temp;

	if (!(pile_a))
		return (-1);
	size = ft_lstsize(pile_a);
	if (size == 1)
		return ((pile_a)->content);
	temp = pile_a;
	result = data.value[1];
	while ((temp))
	{
		if ((temp)->content > val && (temp)->content <= result)
		{
			result = (temp)->content;
		}
		(temp) = (temp)->next;
	}
	return (result);
}

void	litlesort(t_list **pile_a, t_list **pile_b, t_data data)
{
	int		i;
	t_data	data_temp;

	i = -1;
	while (++i < data.nb[3] - 3)
	{
		put_val_top(pile_a, data.tab[i], 'a');
		push(pile_b, pile_a, 'b');
	}
	data_temp.tab = put_tab(*pile_a, 3);
	sort3(pile_a, data_temp);
	i = -1;
	while (++i < data.nb[3] - 3)
		push(pile_a, pile_b, 'a');
	free(data_temp.tab);
}
