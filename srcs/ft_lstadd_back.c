/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 18:11:49 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/26 01:03:32 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*l;

	l = *alst;
	if (!new)
		return ;
	if (!alst || !(*alst))
		*alst = new;
	else
	{
		while ((l->next))
			l = l->next;
		l->next = new;
	}
}
