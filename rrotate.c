/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:27:46 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/15 15:42:51 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/push_swap.h"

void	rrotate(t_list *pile_x)
{
	ft_lstadd_front(&pile_x, ft_lstlast(pile_x));
	ft_lstclear(ft_lstlast(pile_x));
}

void	rrr(t_list *pile_a, t_list *pile_b)
{
	rotate(t_list pile_a);
	rotate(t_list pile_b);
}
