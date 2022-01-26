/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 12:43:51 by brhajji-          #+#    #+#             */
/*   Updated: 2021/11/28 12:00:06 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*src;

	src = (char *)s;
	while (*src)
	{
		if (*src == (char) c)
			return (src);
		src++;
	}
	if (*src == (char) c)
		return (src);
	return (NULL);
}
