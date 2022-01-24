/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tribig.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 16:15:47 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/21 19:13:12 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
void sortbig(t_list **pile_a, t_list **pile_b, t_data data, int nbPivot)
{
	int x;
	int	i;
	t_data data_temp;

	x = -1;
	i = 0;
	/*while (i < data.nb[nbPivot] - 1)
	{
		if ((*pile_a)->content == data.tab[data.nb[nbPivot] - 1])
			rotate(pile_a, 'a');
		else
		{
			push(pile_b, pile_a, 'b');
			if ((*pile_b)->content <= data.tab[nbPivot / 2])
				rotate(pile_b, 'b');
			i++;
		}
	}*/
	while (++x < nbPivot + 1)
	{
		
		while (i < data.nb[x] - x)
		{
            if (i % 2 == 1)
            {
                if (x < nbPivot)
				    put_val_top(pile_a, get_next_inf(*pile_a, data.value[x], nbPivot, data), 'a');
                if (x == nbPivot)
                    put_val_top(pile_a, data.tab[i + x], 'a');
                if (((x == nbPivot) || (*pile_a)->content < data.value[x]) &&
                        is_data((*pile_a)->content, nbPivot, data) == 0)
                {
                    i++;
                    push(pile_b, pile_a, 'b');
                    rotate(pile_b, 'b');
                }
            }
            else 
            {
                if (x < nbPivot)
				    put_val_top(pile_a, get_next_inf(*pile_a, data.value[x], nbPivot, data), 'a');
                if (x == nbPivot)
                    put_val_top(pile_a, data.tab[i + x], 'a');
                if (((x == nbPivot) || (*pile_a)->content < data.value[x]) &&
                        is_data((*pile_a)->content, nbPivot, data) == 0)
                {
                    i++;
                    push(pile_b, pile_a, 'b');
                }
            }
			
		}
	}
	//sort_suite(pile_a, pile_b, data, nbPivot);
    print_pile(*pile_a, *pile_b);
    
	//sortbig_suite(pile_a, pile_b, data, nbPivot);
}

void sortbig_suite(t_list **pile_a, t_list **pile_b, t_data data, int nbPivot)
{
	int	i;
	int a;
	int b;
	int x;

	i = -1;

	while (++i < data.nb[nbPivot] - 1)
	{
		b = get_best(*pile_a, *pile_b, data);
		a = get_next_sup(*pile_a, b, nbPivot, data);
		if (get_pos(*pile_b, b) > ((ft_lstsize(*pile_b)) / 2)
			&& get_pos(*pile_a, a) > ((ft_lstsize(*pile_a)) / 2))
			{
				while (b != (*pile_b)->content && a != (*pile_a)->content)
					rrr(pile_a, pile_b);
			}
		else if (get_pos(*pile_b, b) <= ((ft_lstsize(*pile_b)) / 2) 
		&&  get_pos(*pile_a, a) <= ((ft_lstsize(*pile_a)) / 2))
		{
			while (b != (*pile_b)->content && a != (*pile_a)->content)
				rr(pile_a, pile_b);
		}
		put_val_top(pile_b, b, 'b');
		put_val_top(pile_a, a, 'a');
		push(pile_a, pile_b, 'a');
	}
	x = get_pos(*pile_a, data.tab[0]);
	while ((*pile_a)->content != data.tab[0])
	{
		if (x > ((data.nb[nbPivot]) / 2))
			rrotate(pile_a, 'a');
		else
			rotate(pile_a, 'a');
	}
}