/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 12:24:32 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/20 12:32:33 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	is_sort(t_list *pile_x)
{
	int	x;
	t_list	*pile_tmp;

	x = 0;
	pile_tmp = pile_x;
	if (!pile_x)
		return (-1);
	while (pile_tmp && pile_tmp->next)
	{
		if (pile_tmp->content > pile_tmp->next->content)
			return (x);
		else
		{
			x++;
			pile_tmp = pile_tmp->next;
		}
	}
	return (x);
}
