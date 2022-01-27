/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:22:31 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/27 14:30:16 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	ft_strcmp(char *str1, char *str2)
{
	while (str1 && str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (!str1 && !str2)
		return (0);
	return ((*str1 - *str2));
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	check_digit(char **tmp, int size)
{
	int	i;
	int	len;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		len = ft_strlen(tmp[i]);
		while (j < len)
		{
			if (!ft_isdigit(tmp[i][j]) || (j == 0 && tmp[i][j] != '-'
				&& !ft_isdigit(tmp[i][j])))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**check_part2(int ac, char **av)
{
	char	**tmp;

	if (!av[1][0])
		return (0);
	if (ac == 2)
		tmp = ft_split(av[1], ' ');
	else
		tmp = ++av;
	if ((!tmp) || !check_digit(tmp, tlen(tmp)))
	{
		freetab(tmp, tlen(tmp), ac);
		return (NULL);
	}
	return (tmp);
}

int	input_check(int ac, char **av)
{
	int		x;
	int		i;
	char	**tmp;

	x = -1;
	tmp = check_part2(ac, av);
	if (!tmp || !(*tmp))
		return (0);
	while (++x < tlen(tmp))
	{
		i = x;
		if ((ft_strcmp(tmp[x], "2147483648") > 0 && tmp[x][0] != '-'
			&& ft_strlen(tmp[x]) >= 10) || (tmp[x][0] == '-'
			&& ft_strcmp(tmp[x], "-2147483649") > 0 && ft_strlen(tmp[x]) >= 11))
			return (freetab(tmp, tlen(tmp), ac));
		while (++i < tlen(tmp))
		{
			if (ft_atoi(tmp[x]) == ft_atoi(tmp[i]))
				return (freetab(tmp, tlen(tmp), ac));
		}
	}
	freetab(tmp, tlen(tmp), ac);
	return (1);
}
