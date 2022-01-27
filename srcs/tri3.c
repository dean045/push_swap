/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 14:48:22 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/27 15:02:58 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_tmp(int tmp, int size_b, int size_a, int i)
{
	if (tmp > (size_a / 2))
		tmp = (size_a) - tmp;
	if (i > (size_b / 2))
		tmp += size_b - i;
	else
		tmp += i;
	return (tmp);
}

int	get_best(t_list *pile_a, t_list *pile_b, t_data data)
{
	int	op;
	int	tmp;
	int	i;
	int	size;
	int	val;

	i = -1;
	size = ft_lstsize(pile_b);
	val = (pile_b)->content;
	op = get_pos(pile_a, get_next_sup(pile_a, (pile_b)->content, data));
	while (op && pile_b)
	{
		tmp = get_pos(pile_a, get_next_sup(pile_a, (pile_b)->content, data));
		tmp = get_tmp(tmp, size, ft_lstsize(pile_a), ++i);
		if (tmp <= op)
		{
			val = (pile_b)->content;
			op = tmp;
		}
		pile_b = (pile_b)->next;
	}
	return (val);
}
