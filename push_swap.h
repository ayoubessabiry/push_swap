/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:22:18 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/16 17:21:39 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;
void	push(t_node **a, t_node **b, int i);
void	ft_putstr_fd(char *s, int fd);
void	print(t_node *head);
void	swap(t_node **a, int i);
void	rotate(t_node **a, int i);
void	revrotate(t_node **a, int i);
void	check_dup(t_node *a);
void	ft_error(char *s);
void	sort(t_node **a, t_node **b);
void	push_to_b(t_node **a, t_node **b, int *arr, int max);
void	find_min(t_node **a);
void	find_m_a(t_node **a, t_node **b);
void	ft_rotate(t_node **a, t_node **b);
void	ft_revrotate(t_node **a, t_node **b);
void	sort_min(t_node **a, t_node **b);
void	sort_3(t_node **a);
void	sort_4(t_node **a, t_node **b);
char	**ft_split(char const *s, char c);
int		*arr_get(int s);
int		*get_dup(t_node *a);
int		check_push(t_node *a, t_node **b);
int		check_if_max(t_node *a, int b);
int		ft_atoi(char *str);
int		*longest(t_node *a, int s);
int		get_max(int *arr, int size);
int		sorted(t_node *a);
int		find_max(t_node *a, int m);
int		len_l(t_node *a);
int		find_max_a(t_node *a);
int		get_last(t_node **a);
int		find_min_a(t_node *a);
int		ft_rot(t_node *a, int b);
#endif