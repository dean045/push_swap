/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:05:06 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/06 17:25:43 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void reset_rot(t_list **pile_a, int rot, int val, int size)
{
    while (rot && (*pile_a)->content >= val)
	{
		if (rot >= (size/ 2))
		{
			rrotate(pile_a, 'a');
		}
		else
		{
			rotate(pile_a, 'a');
		}
	}
}

void sort_five(t_list **pile_a, t_list **pile_b, t_data data)
{
	t_data data_temp;

    put_val_top(pile_a, data.tab[4]);
    push(pile_b, pile_a, 'b');
    put_val_top(pile_a, data.tab[0]);
    push(pile_b, pile_a, 'b');
    data_temp.tab = put_in_tab(*pile_a, 3);
    sort3(pile_a, data_temp);
    push(pile_a, pile_b, 'a');
    push(pile_a, pile_b, 'a');
    rotate(pile_a, 'a');
}

int get_next(t_list **pile_a, int val, int nbPivot, t_data data)
{
	int x;
    int size;
    t_list  *temp;

    size = ft_lstsize(*pile_a);
	if (!(*pile_a))
		return (-1);
	x = 0;
    temp = *pile_a;
	while ((temp)->content >= val && is_data((temp)->content, nbPivot, data) == 0)
	{
		(temp) = (temp)->next;
	}
    //put_val_top(pile_a, (temp)->content);
    //reset_rot(pile_a, x , val, size);
	return ((temp)->content);
}

int is_data(int val, int nbPivot, t_data data)
{
    int i;

    i = -1;
    while(++i < nbPivot)
    {
        if (val == data.value[i])
            return (1);
    }
    return (0);
}