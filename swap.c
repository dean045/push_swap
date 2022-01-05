/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:06:45 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/17 17:35:55 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/push_swap.h"

void	swap(t_list *pile_x, char c)
{
	int	tmp;

	if (ft_lstsize(pile_x) > 1)
	{
		tmp = pile_x->content;
		pile_x->content = pile_x->next->content;
		pile_x->next->content = tmp;
		if (c)
		{
			write(1,"s", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
	}
}

void	ss(t_list *pile_a, t_list *pile_b)
{
	swap(pile_a, 0);
	swap(pile_b, 0);
	write(1,"ss\n", 3);
}
