/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:24:06 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/27 14:38:35 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

void	*rotate(t_list **pile_x, char c)
{
	t_list	*tmp;

	if (*pile_x && (*pile_x)->next)
	{
		tmp = *pile_x;
		*pile_x = (*pile_x)->next;
		ft_lstlast(*pile_x)->next = tmp;
		tmp->next = NULL;
		if (c)
		{
			write(1, "r", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
	}
	return (*pile_x);
}

void	rr(t_list **pile_a, t_list **pile_b)
{
	rotate(pile_a, 0);
	rotate(pile_b, 0);
	write(1, "rr\n", 3);
}
