/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:18:16 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/25 16:57:26 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"includes/push_swap.h"

void	push(t_list **pile_a, t_list **pile_b)
{
	t_list	*tmp;

	if (!*pile_b)
		return ;
	if (*pile_b && (*pile_b)->content)
	{
		tmp = *pile_b;
		*pile_b = (*pile_b)->next;
		tmp->next = *pile_a;
		*pile_a = tmp;
	}
	tmp = *pile_b;
	if (tmp == NULL)
	{
		free(*pile_b);
		*pile_b = (NULL);
		return ;
	}
}
