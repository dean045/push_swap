/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:35 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/26 17:25:48 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>
void print_pile(t_list *pile_a, t_list *pile_b)
{
	int x = 0;
	printf("|A| |B|\n");
	while ((pile_a) || (pile_b))
	{
		if (pile_a)
		{
			printf("|%i| ", pile_a->content);
			pile_a = pile_a->next;
		}
		else
			printf("| | ");
		if (pile_b)
		{
			printf("|%i|\n", pile_b->content);
			pile_b = pile_b->next;
		}
		else
			printf("| |\n");
		x++;
	}
	printf("\n");
}
int ft_sqrt(int x)
{
	int	tmp;

	tmp = 1;
	while(tmp <= 200 && tmp * tmp < x)
	{
		if ((tmp + 1) * (tmp + 1) > x)
			return (tmp);
		tmp++;
	}
	return (tmp);
}

t_data	get_data(int *tab, int size, int nbPivot)
{
	t_data	data;

	data.tab = tab;
	data.nb[2] = size;
	data.value[0] = tab[(size - 1) / 2];
	data.nb[0] = (size - 1) / 2;
	data.value[1] = tab[(size - 1)];
	data.nb[1] = (size - 1);
	return (data);
}

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_data	data;
	int		size;
	
	pile_b = NULL;
	pile_a = NULL;
	if (ac > 1)
	{
		if (input_check(ac, av))
			pile_a = (t_list *)init(ac, av);
		else
		{
			printf("erreur de saisi");
			return (0);
		}
		size = ft_lstsize(pile_a);
		data.tab = put_in_tab(pile_a, size);
		data = get_data(data.tab, size, 2);
		//printf("value 0 = %i, value 1 = %i, nb 0 = %i, nb 1 = %i\n", data.value[0],data.value[1],data.nb[0],data.nb[1]);
		sort(&pile_a, &pile_b, data, 2);
		//print_pile(pile_a, pile_b);
	}
	return (0);
}
