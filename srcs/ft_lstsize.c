/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:56:28 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/25 21:32:13 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

int	ft_lstsize(t_list *lst)
{	
	int		i;

	if (!lst)
		return (0);
	i = 1;
	while (lst && lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
