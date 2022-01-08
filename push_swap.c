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
	while(tmp <= 46340 && tmp * tmp < x)
	{
		if ((tmp + 1) * (tmp + 1) > x)
			return (tmp);
		tmp++;
	}
	return (tmp);
}

t_data	get_data(int *tab, int size)
{
	int		i;
	t_data	data;

	i = -1;
	data.tab = tab;
	data.nb[3] = size;
	while(++i < size)
	{
		if (i == (size / 4))
		{
			data.value[0] = tab[i];
			data.nb[0] = i;
		}
		else if (i == (size / 2))
		{
			data.value[1] = tab[i];
			data.nb[1] = i;
		}
		else if (i == (size / 2) + (size / 4))
		{
			data.value[2] = tab[i];
			data.nb[2] = i;
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
		data = get_data(data.tab, size);
		//int i = -1;
		//while (++i < size)
		//printf("tab[%i] = %i\n", i , data.tab[i]);
		//printf("nb[0] = %i nb[1] = %i nb[2] = %i nb[3] = %i\n", data.nb[0], data.nb[1], data.nb[2], data.nb[3]);
		//printf("%i %i %i\n", data.value[0], data.value[1], data.value[2]);
	//while(!is_sort(pile_a))
		sort(&pile_a, &pile_b, data);
		//print_pile(pile_a, pile_b);
		//printf("%i %i %i\n", data.value[0], data.value[1], data.value[2]);
		
	////printf("%i %i %i %i\n", data.nb[0], data.nb[1], data.nb[2], data.nb[3]);
		//tri(&pile_a, &pile_b, &count);
		//push(&pile_b, &pile_a, 'b');
		//
		////printf("%i\n", is_sort(pile_a));
	}
	return (0);
}
