/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:30 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/14 15:22:23 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	*ft_free(t_elem *pile)
{
	free(pile);
	return (NULL);
}


void	*init(int ac, char **av, t_elem *pile_a)
{
	int		x;
	t_elem	*tmp;

	pile_a = malloc(sizeof(t_elem) * ac);
	if (pile_a)
		return (NULL);
	tmp = malloc(sizeof(t_elem));
	if (!tmp)
	{
		free(pile_a);
		pile_a = NULL;
		return (NULL);
	}
	tmp->next = NULL;
	x = ac;
	while (--x > 0)
	{
		tmp->content = ft_atoi(char[x]);
		ft_lstadd_front(&pile_a, tmp);
	}
	free(tmp);
	tmp = NULL;
}
