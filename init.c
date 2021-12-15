/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:30 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/15 12:15:20 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_list	*ft_free(t_list *pile)
{
	free(pile);
	return (NULL);
}


t_list	*init(int ac, char **av)
{
	int		x;
	int		p;
	t_list	*tmp;
	t_list	*pile_tmp;

	pile_tmp = malloc(sizeof(t_list ) * (ac - 1));
	if (!pile_tmp)
		return (NULL);
	p = ft_atoi(av[1]);
	pile_tmp = ft_lstnew(&p);
	x = 1;
	while (++x < ac)
	{
		p = ft_atoi(av[x]);
		tmp = ft_lstnew(&p);
		ft_lstadd_back(&pile_tmp, tmp);
	}
	return (pile_tmp);
}
