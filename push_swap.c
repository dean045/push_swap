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

t_data	*get_data(int *tab, int size)
{
	int		i;
	t_data	*data;

	data= malloc(sizeof(t_data *));
	if (!data)
		return (NULL);
	i = -1;
	while(++i < size)
	{
		if (i == (size / 4))
		{
			data->min = tab[i];
			data->nb_min = i;
		}
		else if (i == (size / 2))
		{
			data->mid = tab[i];
			data->nb_mid = i;
		}
		else if (i == ((size * 3) / 4))
			data->max = tab[i]; 
	}
	return (data);
}

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_data	*data;
	int		*tab;
	int		size;
	int		count;
	
	pile_b = NULL;
	pile_a = NULL;
	count = 0;
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
		tab = put_in_tab(pile_a, size);
		data = get_data(tab, size);
		//printf("p1 = %i // p2 = %i // p3 = %i \n", data->min, data->mid, data->max);
		//print_pile(pile_a, pile_b);
		//split_by_two(&pile_a, &pile_b, ft_sqrt(ft_lstsize(pile_a)));
		/*pile_a = rotate(pile_a);
		//print_pile(pile_a, pile_b);	
		pile_a = rrotate(pile_a);
		//print_pile(pile_a, pile_b);
		//print_pile(pile_a, pile_b);
		push(pile_b, pile_a);
		//print_pile(pile_a, pile_b);
		//print_pile(pile_a, pile_b);	
		pile_b = push(&pile_a, pile_b);
		swap(pile_a);
		//print_pile(pile_a, pile_b);
		push(pile_b, pile_a);
		push(pile_b, pile_a);
		//print_pile(pile_a, pile_b);
		rr(&pile_b, &pile_a);
		//print_pile(pile_a, pile_b);
		rrr(&pile_b, &pile_a);
		//print_pile(pile_a, pile_b);
		ss(pile_b, pile_a);*/
	//	while (!is_sort(pile_a))	
	//	tri2(&pile_a, &pile_b, &count);
	while(!is_sort(pile_a))
		sort(&pile_a, &pile_b, &count, data);
		//tri(&pile_a, &pile_b, &count);
		//push(&pile_b, &pile_a, 'b');
		//print_pile(pile_a, pile_b);
		//printf("%i\n", is_sort(pile_a));
	}
	return (0);
}
