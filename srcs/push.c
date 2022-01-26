/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:18:16 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/25 21:31:44 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

void	push(t_list **pile_a, t_list **pile_b, char c)
{
	t_list	*tmp;


		tmp = *pile_b;
		*pile_b = (*pile_b)->next;
		tmp->next = *pile_a;
		*pile_a = tmp;
		write(1,"p", 1);
		write(1, &c, 1);
		write(1, "\n", 1);
}
