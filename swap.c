/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:06:45 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/17 00:38:43 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/push_swap.h"

void	swap(t_list *pile_x)
{
	int	tmp;

	if (ft_lstsize(pile_x) > 1)
	{
		tmp = pile_x->content;
		pile_x->content = pile_x->next->content;
		pile_x->next->content = tmp;
	}
}

void	swap_s(t_list *pile_a, t_list *pile_b)
{
	swap(pile_a);
	swap(pile_b);
}
