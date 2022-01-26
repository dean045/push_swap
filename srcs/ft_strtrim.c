/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:16:36 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/25 21:32:13 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"
#include<stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		taille;
	int		i;
	char	*new;

	if (!s1)
		return (NULL);
	taille = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] && ft_strchr(set, (int)s1[i]))
		i++;
	while (s1[i] && ft_strchr(set, (int)s1[taille]))
		taille--;
	new = ft_substr(s1, i, taille - i + 1);
	return (new);
}
