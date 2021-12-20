/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:56:17 by brhajji-          #+#    #+#             */
/*   Updated: 2021/12/20 16:16:43 by brhajji-         ###   ########.fr       */
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
t_list	*init(int ac, char **av);

void	*rrotate(t_list *pile_x);
void	rrr(t_list **pile_a, t_list **pile_b);
void	rr(t_list **pile_a, t_list **pile_b);
void	*rotate(t_list *pile_x);
void	*push(t_list **pile_a, t_list *pile_b);
t_list	split_by_two(t_list **pile_a, t_list **pile_b);
int		get_max(t_list *pile_x);
int		get_min(t_list *pile_x);
void	swap(t_list *pile_x);
void	ss(t_list *plie_a, t_list *pile_b);

#endif



