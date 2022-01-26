/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brhajji- <brhajji-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:56:17 by brhajji-          #+#    #+#             */
/*   Updated: 2022/01/26 17:12:47 by brhajji-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include<stdlib.h>
#include<unistd.h>
#include <stdio.h>
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;
typedef struct	s_data
{
	int nb[23];
	int	value[23];
	int	*tab;
}				t_data;

int		ft_atoi(const char *str);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int *content);
int		ft_lstsize(t_list *lst);
char	**ft_split(char const *str, char c);
size_t	ft_strlen(const char *s);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);

void 	freetab(char **tab, int size, int ac);
void	ft_free(t_list **pile_a, t_data data);
int 	get_best(t_list *pile_a, t_list *pile_b, t_data data);
int		input_check(int ac, char **av);
void	sort_suite(t_list **pile_a, t_list **pile_b, t_data data);
int 	get_best(t_list *pile_a, t_list *pile_b, t_data data);
int 	get_next_sup(t_list *pile_a, int val, t_data data);
int 	is_data(int val, int nbPivot, t_data data);
void 	sort_five(t_list **pile_a, t_list **pile_b, t_data data);
void	print_pile(t_list *pile_a, t_list *pile_b);
int		is_sort(t_list *pile_x);
t_list	*init(int ac, char **av);
void 	tri(t_list **pile_a, t_list **pile_b, t_data data, int size);
void 	litlesort(t_list **pile_a, t_list **pile_b, t_data data);
void	*rrotate(t_list **pile_x, char c);
void	rrr(t_list **pile_a, t_list **pile_b);
void	rr(t_list **pile_a, t_list **pile_b);
void	*rotate(t_list **pile_x, char c);
void	push(t_list **pile_a, t_list **pile_b, char c);
void	swap(t_list *pile_x, char c);
void	ss(t_list *plie_a, t_list *pile_b);
void	tri2(t_list **pile_a, t_list **pile_b);
int		get_mediane(t_list *pile_a);
void	sort3(t_list **pile_a, t_data data);
void    sort(t_list **pile_a, t_list **pile_b, t_data data);
int		*put_tab(t_list *pile_a, int size);
t_data	get_data(int *tab, int size,int nbPivot);
int 	put_val_top(t_list **pile_a, int val, char c);
int 	get_pos(t_list *pile_a, int val);
int 	tlen(char **tab);

#endif



