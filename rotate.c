/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:24:06 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/21 12:32:01 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/push_swap.h"

void	*rotate(t_list *pile_x)
{
	t_list *tmp;

	if (pile_x->next)
	{
		tmp = pile_x;
		pile_x = pile_x->next;
		ft_lstlast(pile_x)->next = tmp;
		tmp->next = NULL;
	}
	return (pile_x);
}

void	rr(t_list **pile_a, t_list **pile_b)
{
	*pile_a = rotate(*pile_a);
	*pile_b = rotate(*pile_b);
}
