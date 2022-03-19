/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 09:41:20 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/16 16:07:13 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_a(t_node *a)
{
	int	max;
	int	i;
	int	j;
	int	len;

	len = len_l(a);
	max = a->data;
	j = 0;
	i = 0;
	while (a)
	{
		if (a->data > max)
		{
			max = a->data;
			j = i;
		}
		i++;
		a = a->next;
	}
	if (j + 1 == len)
		return (0);
	return (j + 1);
}

int	find_min_a(t_node *a)
{
	int	min;
	int	i;
	int	j;

	min = a->data;
	j = 0;
	i = 0;
	while (a)
	{
		if (a->data < min)
		{
			min = a->data;
			j = i;
		}
		i++;
		a = a->next;
	}
	return (j);
}

int	check_if_max(t_node *a, int b)
{
	while (a)
	{
		if (b < a->data)
			return (0);
		a = a->next;
	}
	return (1);
}

int	get_last(t_node **a)
{
	int	last;

	revrotate(a, 0);
	last = (*a)->data;
	rotate(a, 0);
	return (last);
}

void	sort_4(t_node **a, t_node **b)
{
	find_m_a(a, b);
	if (!sorted(*a))
		sort_3(a);
	push(b, a, 0);
}
