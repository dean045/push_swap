/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:22:31 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/14 15:30:40 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	input_check(int ac, char **av)
{
	int x ;

	x = 0;
	while (++x < ac)
	{
		if ((av[x][0] == '-' && ft_strlen(av[x]) > 11) || ft_strlen(av[x]) > 10)
			return (0);
		if (ft_atoi(av[x]) > 2147483647 || ft_atoi(av[x]) < -2147483648)
			return (0);
	}
	return (1);
}
