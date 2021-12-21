/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:24:32 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/21 18:49:40 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sort(t_list *pile_x)
{
	t_list	*pile_tmp;

	pile_tmp = pile_x;
	if (!pile_x || !pile_x->content)
		return (-1);
	while (pile_tmp && pile_tmp->next)
	{
		if (pile_tmp->content > pile_tmp->next->content)
			return (0);
		else
			pile_tmp = pile_tmp->next;
	}
	return (1);
}
