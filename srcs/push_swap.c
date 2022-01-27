/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:53:35 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/27 20:21:04 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_data	getbig_data(int *tab, int size, int nbPivot)
{
	int		i;
	int		x;
	t_data	data;

	i = -1;
	x = -1;
	data.tab = tab;
	data.nb[nbPivot] = size;
	while (++i < size && x < nbPivot)
	{
		if (i == size - 1 || (i % (size / nbPivot)) == 0)
		{
			if (i == size - 1)
			{
				data.value[++x] = tab[i - 1];
				data.nb[x] = size;
			}
			else
			{
				data.value[x] = tab[i];
				data.nb[x] = i;
			}
		}
	}
	return (data);
}

t_data	get_data(int *tab, int size, int nbPivot)
{
	t_data	data;

	data.tab = tab;
	data.nb[nbPivot] = size;
	data.value[0] = tab[(size - 1) / 2];
	data.nb[0] = (size - 1) / 2;
	data.value[1] = tab[(size - 1)];
	data.nb[1] = (size - 1);
	return (data);
}

void	tri(t_list **pile_a, t_list **pile_b, t_data data, int size)
{
	if (size == 3 && !is_sort(*pile_a))
	{
		data = getbig_data(data.tab, size, size);
		sort3(pile_a, data);
	}
	else if (size == 5 && !is_sort(*pile_a))
	{
		data = getbig_data(data.tab, size, size);
		sort_five(pile_a, pile_b, data);
	}
	else if (size <= 10 && !is_sort(*pile_a))
	{
		data = getbig_data(data.tab, size, 3);
		litlesort(pile_a, pile_b, data);
	}
	else if (size > 10 && !is_sort(*pile_a))
	{
		data = get_data(data.tab, size, 2);
		sort(pile_a, pile_b, data);
	}
}

int	main(int ac, char **av)
{
	t_list	*pile_a;
	t_list	*pile_b;
	t_data	data;

	pile_b = NULL;
	pile_a = NULL;
	if (ac > 1)
	{
		if (!input_check(ac, av))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		pile_a = (t_list *)init(ac, av);
		data.tab = put_tab(pile_a, ft_lstsize(pile_a));
		if (ft_lstsize(pile_a) == 2 && !is_sort(pile_a))
			rotate(&pile_a, 'a');
		else if (ft_lstsize(pile_a) > 2 && !is_sort(pile_a))
			tri(&pile_a, &pile_b, data, ft_lstsize(pile_a));
	}
	return (ft_free(&pile_a, data));
}
