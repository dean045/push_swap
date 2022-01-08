/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:30 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/26 15:42:19 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int tmp;

	i = 0;
	tmp = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

int	*put_in_tab(t_list *pile_a, int size)
{
	int i;
	int	*tab;

	tab = malloc(sizeof(int) * size);
	i = -1;
	if (!tab)
		return (NULL);
	while (++i < size)
	{
		tab[i] = pile_a->content;
		pile_a = pile_a->next;
	}
	return (sort_tab(tab, size));
}

t_list	*ft_free(t_list *pile)
{
	free(pile);
	return (NULL);
}

t_list	split_by_two(t_list **pile_a, t_list **pile_b, int x)
{
	while (x)
	{
		push(pile_b, pile_a, 'b');
		x--;
	}
}
t_list	*init(int ac, char **av)
{
	int		x;
	int		p;
	t_list	*tmp;
	t_list	*pile_tmp;

	pile_tmp = malloc(sizeof(t_list ) * (ac));
	if (!pile_tmp)
		return (NULL);
	p = ft_atoi(av[1]);
	pile_tmp = ft_lstnew(&p);
	x = 2;
	while (x < ac)
	{
		p = ft_atoi(av[x]);
		tmp = ft_lstnew(&p);
		ft_lstadd_back(&pile_tmp, tmp);
		x++;
	}
	return (pile_tmp);
}
