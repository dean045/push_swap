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

void reset_rot(int rot, t_list **pile_a)
{
    if (rot > 0)
    {
        while (rot != 0)
        {
            rrotate(pile_a, 'a');
            rot--;
        }
    }
    else if (rot < 0)
    {
        while (rot != 0)
        {
            rotate(pile_a, 'a');
            rot++;
        }
    }
}

void sort_five(t_list **pile_a, t_list **pile_b, t_data data)
{

     put_val_top(pile_a, data.tab[4]);
     push(pile_b, pile_a, 'b');
      put_val_top(pile_a, data.tab[0]);
     push(pile_b, pile_a, 'b');
        sort3(pile_a, data);
        push(pile_a, pile_b, 'a');
        push(pile_a, pile_b, 'a');
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