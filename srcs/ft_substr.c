/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 12:19:17 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/25 21:32:13 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"
#include<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*nouveau;

	if (s && start >= ft_strlen(s))
	{
		nouveau = malloc(sizeof(char));
		nouveau[0] = '\0';
		return (nouveau);
	}
	nouveau = malloc(sizeof(char) * (len + 1));
	i = 0;
	if (!nouveau || !s)
		return (NULL);
	nouveau[len] = '\0';
	while (i < len && s[i + start])
	{
		nouveau[i] = (char)s[i + start];
		i++;
	}
	return (nouveau);
}
