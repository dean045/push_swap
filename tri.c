/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:05:06 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/26 17:25:43 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include <stdio.h>

int get_pos(t_list *pile_a, int val)
{
	int x;

	if (!pile_a)
		return (-1);
	x = 0;
	while (pile_a && pile_a->next && pile_a->content != val)
	{
		x++;
		pile_a = pile_a->next;
	}
	if (pile_a->content != val && x == ft_lstsize(pile_a))
		return (-1);
	return (x);
}

int put_val_top(t_list **pile_a, int val, int *count)
{
	int size;
	int pos;
	int rot;

	if (!*pile_a || ft_lstsize(*pile_a) < 2)
		return (0);
	size = ft_lstsize(*pile_a);
	pos = get_pos(*pile_a, val);
	rot = 0;
	while ((*pile_a)->content != val)
	{
		if (pos >= (size / 2) - 1)
		{
			rrotate(pile_a, 'a');
			rot--;
		}
		else
		{
			rotate(pile_a, 'a');
			rot++;
		}
		(*count)++;
		//printf("teset   %i\n", *count);
	}
	return (rot);
}

void sort3(t_list **pile_a, int *count, t_data *data)
{
	while (!is_sort(*pile_a))
	{
		if ((*pile_a)->content == data->max && (*pile_a)->next->content == data->min)
			(*pile_a) = rotate(pile_a, 'a');
		else if ((*pile_a)->content == data->mid && (*pile_a)->next->content == data->max)
			(*pile_a) = rrotate(pile_a, 'a');
		else if (ft_lstlast(*pile_a)->content == data->max || (*pile_a)->content == data->min || (*pile_a)->next->content == data->mid)
		{
			swap(*pile_a, 'a');
		}
		(*count)++;
	}
}

void sort_suite(t_list **pile_a, t_list **pile_b, int *count, t_data *data)
{
	int size;
	int rot;

	rot = 0;
	size = ft_lstsize(*pile_a);
	while (*pile_b)
	{
		if ((*pile_b)->content > data->max)
		{
			//rot = put_val_top(pile_a, data->max, count);
			//rot++;
			//rrotate(pile_a, 'a');
			push(pile_a, pile_b, 'a');
			if ((*pile_a)->content > ft_lstlast(*pile_a)->content)
			{
				rrotate(pile_a, 'a');
				rot++;
				swap(*pile_a, 'a');
			}
			//reset_rot(rot, pile_a);
		}

		else if ((*pile_b)->content <= data->max)
		{
			if ((*pile_b)->content <= data->mid)
			{
				if ((*pile_b)->content <= data->min)
				{
					push(pile_a, pile_b, 'a');
					if ((*pile_a)->content > (*pile_a)->next->content)
						swap(*pile_a, 'a');
				}
				else
				{
					//rot = put_val_top(pile_a, data->mid, count);
					push(pile_a, pile_b, 'a');
					if ((*pile_a)->content > (*pile_a)->next->content)
						swap(*pile_a, 'a');
					//reset_rot(rot, pile_a);
				}
			}
			else
			{
				//rot = put_val_top(pile_a, data->max, count);
				push(pile_a, pile_b, 'a');
				if ((*pile_a)->content > (*pile_a)->next->content)
					swap(*pile_a, 'a');
				//reset_rot(rot, pile_a);
			}
		}
		//print_pile(*pile_a, *pile_b);
	}
}

void sort(t_list **pile_a, t_list **pile_b, int *count, t_data *data)
{
	int x;
	int	i;
	int nb[4];
	int	value[3];

	x = -1;
	i = 0;
	nb[0] = data->nb_min;
	nb[1] = data->nb_mid;
	nb[2] = data->nb_mid + data->nb_min;
	nb[3] = ft_lstsize(*pile_a);
	value[0] = data->min;
	value[1] = data->mid;
	value[2] = data->max;
	while (++x < 4)
	{
		while (i < nb[x])
		{
			printf("i %i / x %i / nb %i",i, x, nb[x] );
			if (((x == 3) || (*pile_a)->content <= value[x]) )
			{
				i++;
				push(pile_b, pile_a, 'b');
				//printf("test\n");
				if ((*pile_b)->next && ((*pile_b)->content < (*pile_b)->next->content))
				{
					*count++;
					swap(*pile_b, 'b');
				}
			}
			else
				rotate(pile_a, 'a');
			//print_pile(*pile_a, *pile_b);
			*count++;
		}
	}
	//sort3(pile_a, count, data);
	//sort_suite(pile_a, pile_b, count, data);
	/*if (!is_sort(*pile_a))
		sort(pile_a, pile_b, count, data);*/
}
