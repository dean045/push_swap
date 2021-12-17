/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:35 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/17 00:36:16 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>
void print_pile(t_list *pile_a, t_list *pile_b)
{
	int x = 0;
	printf("|A| |B|\n");
	while ((pile_a && pile_a->content) || (pile_b && pile_b->content))
	{
		if (pile_a && pile_a->content)
		{
			printf("|%i| ", pile_a->content);
			pile_a = pile_a->next;
		}
		else
			printf("| |");
		if (pile_b && pile_b->content)
		{
			printf("|%i|\n", pile_b->content);
			pile_b = pile_b->next;
		}
		else
			printf("| |\n");
		x++;
	}
}

int	main(int ac, char **av)
{
	t_list	*pile_a = NULL;
	t_list	*pile_b;
	int		x;
	
	if (ac > 1)
	{
		if (input_check(ac, av))
			pile_a = (t_list *)init(ac, av);
		else
			return (0);
		x = 0;
		print_pile(pile_a, pile_b);
		pile_a = rotate(pile_a);
		printf("rotate\n");
		print_pile(pile_a, pile_b);
		pile_a = rrotate(pile_a);
		printf("rrotate \n");
		print_pile(pile_a, pile_b);
		printf("push b\n");
		pile_a = push(&pile_b, pile_a);
		print_pile(pile_a, pile_b);
		printf("push a\n");
		pile_b = push(&pile_a, pile_b);
		print_pile(pile_a, pile_b);	
		printf("swap a\n");
		swap(pile_a);
		print_pile(pile_a, pile_b);
	}
	return (0);
}
