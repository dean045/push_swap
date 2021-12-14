/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:35 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/14 15:50:01 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include<stdio.h>
int	main(int ac, char **av)
{
	t_elem	*pile_a = NULL;
	//t_elem	*pile_b;
	int		x;

	if (ac > 1)
	{
		if (input_check(ac, av))
			pile_a = init(ac, av, pile_a);
		else
			return (0);
		x = 0;
		while (pile_a)
		{
			printf("elem %i = %i\n", x, *(pile_a->content));
			pile_a = pile_a->next;
		}
	}
	return (0);
}
