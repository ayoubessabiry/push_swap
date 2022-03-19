/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:04:32 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/16 16:07:24 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min(t_node **a, t_node **b, int min, int pos)
{
	t_node	*tmp;
	int		i;

	i = len_l(*a);
	tmp = *a;
	while (tmp)
	{
		if (tmp->data != min && pos <= (i / 2))
		{
			tmp = tmp->next;
			rotate(a, 1);
		}
		else if (tmp->data != min && pos > (i / 2))
		{
			revrotate(a, 1);
			tmp = *a;
		}
		else
		{
			push(a, b, 1);
			break ;
		}
	}	
}

void	find_m_a(t_node **a, t_node **b)
{
	int		min;
	int		i;
	int		pos;
	t_node	*tmp;

	i = 0;
	tmp = *a;
	min = tmp->data;
	while (tmp)
	{
		if (tmp->data < min)
		{
			min = tmp->data;
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	i--;
	push_min(a, b, min, pos);
}

void	sort_3(t_node **a)
{
	if ((*a)->data < (*a)->next->data
		&& (*a)->data < (*a)->next->next->data)
	{
		rotate(a, 1);
		swap(a, 0);
		revrotate(a, 1);
	}
	else if ((*a)->data > (*a)->next->data
		&& (*a)->data > (*a)->next->next->data)
	{
		if ((*a)->next->data < (*a)->next->next->data)
			find_min(a);
		else
		{
			swap(a, 0);
			revrotate(a, 1);
		}
	}
	else if ((*a)->data < (*a)->next->data
		&& (*a)->data > (*a)->next->next->data)
		revrotate(a, 1);
	else if ((*a)->data > (*a)->next->data
		&& (*a)->data < (*a)->next->next->data)
		swap(a, 0);
}

int	sorted(t_node *a)
{
	while (a->next)
	{
		if (a->data > a->next->data)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_min(t_node **a, t_node **b)
{
	if (sorted(*a))
		return ;
	if (len_l(*a) == 2)
	{
		if ((*a)->data > (*a)->next->data)
			swap(a, 0);
	}
	if (len_l(*a) == 3)
		sort_3(a);
	else if (len_l(*a) == 4)
		sort_4(a, b);
	else if (len_l(*a) == 5)
	{
		find_m_a(a, b);
		sort_4(a, b);
		push(b, a, 0);
	}
}
