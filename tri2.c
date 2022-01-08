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