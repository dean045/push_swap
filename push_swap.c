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
	int		i;
	int		x;
	t_data	data;

	i = -1;
	x = 0;
	data.tab = tab;
	data.nb[nbPivot] = size;
	while(++i < size && x <= nbPivot)
	{
		if (i  && (i % (size / nbPivot)) == 0)
		{
			data.value[x] = tab[i];
			data.nb[x] = i;
			//printf("data.nb[%i] = %i\n", x, data.nb[x]);
			x++;
		}
	}
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
		data = get_data(data.tab, size, 5);
		/*for(int s = 0; s <= 5; s++)
			printf("data.value[%i] = %i \ndata.nb[%i] = %i \n",s, data.value[s], s, data.nb[s]);*/
		
		if (size == 3)
			sort3(&pile_a, data);
		else if (size == 5)
			sort_five(&pile_a, &pile_b, data);
		else
			sort(&pile_a, &pile_b, data, 5);
		print_pile(pile_a, pile_b);
	}
	return (0);
}
