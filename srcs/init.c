/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:30 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/27 12:50:43 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*sort_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

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

int	*put_tab(t_list *pile_a, int size)
{
	int	i;
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

int	tlen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		i++;
	}
	return (i);
}

t_list	*init(int ac, char **av)
{
	int		x;
	int		p;
	char	**tmp;
	t_list	*pile_tmp;

	if (ac > 2)
	{
		tmp = av;
		x = 2;
	}
	else
	{
		tmp = ft_split(av[1], ' ');
		x = 1;
	}
	p = ft_atoi(tmp[x - 1]);
	pile_tmp = ft_lstnew(&p);
	while (x < tlen(tmp))
	{
		p = ft_atoi(tmp[x]);
		ft_lstadd_back(&pile_tmp, ft_lstnew(&p));
		x++;
	}
	freetab(tmp, tlen(tmp), ac);
	return (pile_tmp);
}
