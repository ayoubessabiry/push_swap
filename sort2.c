/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:40:04 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/16 17:23:00 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*arr_get(int s)
{
	int	*arr;
	int	i;

	i = 0;
	arr = malloc(sizeof(int) * s);
	if (!arr)
		return (0);
	while (i < s)
		arr[i++] = 1;
	return (arr);
}

int	*get_dup(t_node *a)
{
	int	*dup;
	int	s;
	int	i;

	i = 0;
	s = len_l(a);
	dup = malloc(sizeof(int) * s);
	if (!dup)
		return (0);
	while (a)
	{
		dup[i++] = a->data;
		a = a->next;
	}
	return (dup);
}

void	ft_rotate(t_node **a, t_node **b)
{
	t_node	*tmp;
	int		last;

	tmp = *a;
	while (tmp)
	{
		last = get_last(a);
		if (((*b)->data > tmp->data && !tmp->next)
			|| ((*b)->data > tmp->data && (*b)->data < tmp->next->data))
		{
			tmp = tmp->next;
			rotate(a, 1);
			push(b, a, 0);
			break ;
		}
		else if ((*b)->data < tmp->data && (*b)->data > last)
		{
			tmp = tmp->next;
			push(b, a, 0);
			break ;
		}
		tmp = tmp->next;
		rotate(a, 1);
	}
}

void	ft_revrotate(t_node **a, t_node **b)
{
	t_node	*tmp;
	int		last;

	tmp = *a;
	while (*a)
	{
		last = get_last(a);
		if ((*b)->data < tmp->data && (*b)->data > last)
		{
			push(b, a, 0);
			break ;
		}
		revrotate (a, 1);
		tmp = *a;
	}	
}
