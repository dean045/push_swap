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
int	get_max(t_list	*pile_x)
{
	int		result;
	t_list	*tmp;

	tmp = pile_x;
	if (!pile_x)
		return (0);
	result = tmp->content;
	while (tmp)
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
	if (!pile_x || !(pile_x->content))
		return (0);
	result = tmp->content;
	while (tmp)
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

t_list	split_by_two(t_list **pile_a, t_list **pile_b, int x)
{
	while (x)
	{
		push(pile_b, pile_a);
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
	//printf("atoi %i \nac %i \n", ft_atoi(av[11]), ac);
	while (x < ac)
	{
		p = ft_atoi(av[x]);
		tmp = ft_lstnew(&p);
		ft_lstadd_back(&pile_tmp, tmp);
		x++;
	}
	printf("%i\n",x);
	/*while (pile_tmp->content)
	{
		printf("%i ", pile_tmp->content);
		pile_tmp = pile_tmp->next;
	}*/
	return (pile_tmp);
}
