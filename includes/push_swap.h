/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:56:17 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/14 15:58:00 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft.h"

typedef struct	s_elem
{
	int				*content;
	struct s_elem	*next;
}				t_elem;

int		input_check(int ac, char **av);
void	*init(int ac, char **av, t_list *pile_a);

#endif



