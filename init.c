/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:30 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/20 16:17:29 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
int	get_max(t_list	*pile_x)
{
	int		result;
	t_list	*tmp;

	tmp = pile_x;
	if (!pile_x)
		return (0);
	result = tmp->content;
	while (tmp->next)
	{
		if (tmp->content > result)
			result = tmp->content;
		tmp = tmp->next;
	}
	return (result);
}

int	get_min(t_list	*pile_x)
{
	int		result;
	t_list	*tmp;

	tmp = pile_x;
	if (!pile_x)
		return (0);
	result = tmp->content;
	while (tmp->next)
	{
		if (tmp->content < result)
			result = tmp->content;
		tmp = tmp->next;
	}
	return (result);
}

t_list	*ft_free(t_list *pile)
{
	free(pile);
	return (NULL);
}

t_list	split_by_two(t_list **pile_a, t_list **pile_b)
{
	int	x;

	x = ft_lstsize(*pile_a) / 2;
	while (x)
	{
		*pile_a = push(pile_b, *pile_a);
		x--;
	}
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
