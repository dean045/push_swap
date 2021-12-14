/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:30 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/14 19:19:46 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	*ft_free(t_list *pile)
{
	free(pile);
	return (NULL);
}


t_list	*init(int ac, char **av, t_list *pile_a)
{
	int		x;
	int		*p;
	t_list	*tmp;

	pile_a = malloc(sizeof(t_list) * (ac - 1));
	p = malloc(sizeof(int *));
	if (!pile_a)
		return (NULL);
	tmp = malloc(sizeof(t_list ));
	if (!tmp)
	{
		free(p);
		free(pile_a);
		pile_a = NULL;
		return (NULL);
	}
	tmp->next = NULL;
	x = ac;
	while (--x > 0)
	{
		free(tmp);
		*p = ft_atoi(av[x]);
		tmp = ft_lstnew(p);
		ft_lstadd_front(&pile_a, tmp);
	}
	free(tmp);
	tmp = NULL;
	return (pile_a);
}
