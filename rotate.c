/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:24:06 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/15 15:27:03 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/push_swap.h"

void	rotate(t_list *pile_x)
{
	ft_lstadd_back(&pile_x, pile_x);
	pile_x = pile_x->next;
}

void	rr(t_list *pile_a, t_list *pile_b)
{
	rotate(t_list pile_a);
	rotate(t_list pile_b);
}
