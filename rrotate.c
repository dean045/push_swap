/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:27:46 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/25 17:03:27 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/push_swap.h"

void	*rrotate(t_list **pile_x)
{
	t_list *tmp;

	tmp = ft_lstlast(*pile_x);
	tmp->next = *pile_x;
	while((*pile_x)->next != tmp)
		*pile_x = (*pile_x)->next;
	(*pile_x)->next = NULL;
	return (tmp);
}

void	rrr(t_list **pile_a, t_list **pile_b)
{
	rrotate(pile_a);
	rrotate(pile_b);
}
