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

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
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
		print_pile(pile_a, pile_b);
		//split_by_two(&pile_a, &pile_b, ft_sqrt(ft_lstsize(pile_a)));
		/*pile_a = rotate(pile_a);
		print_pile(pile_a, pile_b);
		printf("rotate\n");
		pile_a = rrotate(pile_a);
		print_pile(pile_a, pile_b);
		printf("rrotate \n");
		print_pile(pile_a, pile_b);
		printf("push b\n");
		pile_a = push(&pile_b, pile_a);
		print_pile(pile_a, pile_b);
		printf("push a\n");
		print_pile(pile_a, pile_b);	
		pile_b = push(&pile_a, pile_b);
		printf("swap a\n");
		swap(pile_a);
		print_pile(pile_a, pile_b);
		printf("pb pb\n");
		pile_a = push(&pile_b, pile_a);
		pile_a = push(&pile_b, pile_a);
		print_pile(pile_a, pile_b);
		printf("rr\n");
		rr(&pile_b, &pile_a);
		print_pile(pile_a, pile_b);
		printf("rrr\n");
		rrr(&pile_b, &pile_a);
		print_pile(pile_a, pile_b);
		printf("ss\n");
		ss(pile_b, pile_a);*/
	//	while (!is_sort(pile_a))	
	//	tri2(&pile_a, &pile_b, &count);
		tri(&pile_a, &pile_b, &count);
		print_pile(pile_a, pile_b);
		//printf("%i\n", is_sort(pile_a));
	}
	return (0);
}
