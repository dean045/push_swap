/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:22:31 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/25 17:25:08 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	input_check(int ac, char **av)
{
	int x;
	int	i;

	x = 0;
	while (++x < ac)
	{
		i = x;
		if ((av[x][0] == '-' && ft_strlen(av[x]) > 11) || ft_strlen(av[x]) > 10)
			return (0);
		if (ft_atoi(av[x]) > 2147483647 || ft_atoi(av[x]) < -2147483648)
			return (0);
		while (++i < ac)
		{
			if (ft_atoi(av[x]) == ft_atoi(av[i]))
				return (0);
		}
	}
	return (1);
}
