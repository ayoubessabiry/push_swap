/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 09:20:19 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/13 14:31:30 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_node *a, int m)
{
	while (a)
	{
		if (a->data > m)
			return (0);
		a = a->next;
	}
	return (1);
}

int	check_arr(int *arr, int max, t_node *tmp)
{
	while (tmp || (max > 0))
	{
		if (arr[max - 1] != tmp->data)
			return (0);
		max--;
		tmp = tmp->next;
	}
	return (1);
}

void	push_to_b(t_node **a, t_node **b, int *arr, int max)
{
	t_node	*tmp;
	int		i;

	tmp = *a;
	i = max - 1;
	while (!check_arr(arr, max, tmp))
	{
		if (arr[i] == tmp->data)
		{
			rotate(a, 1);
			tmp = *a;
			i--;
		}
		else
		{
			tmp = tmp->next;
			push(a, b, 1);
		}
	}
	free(arr);
}

void	ft_sort_m(t_node **a, t_node **b)
{
	int	i;

	if (check_if_max(*a, (*b)->data))
	{
		i = find_max_a(*a);
		while (i)
		{
			rotate(a, 1);
			i--;
		}
		push(b, a, 0);
	}
	else
	{
		i = find_min_a(*a);
		while (i)
		{
			rotate(a, 1);
			i--;
		}
		push(b, a, 0);
	}
}

void	sort(t_node **a, t_node **b)
{
	t_node	*tmp;
	t_node	*tmp1;
	int		min;

	tmp = *a;
	while (*b)
	{
		min = check_push(*a, b);
		tmp1 = *b;
		if (ft_rot(*a, tmp1->data) == len_l(*a))
			ft_sort_m(a, b);
		else if (ft_rot(*a, tmp1->data) <= (len_l(*a) / 2))
			ft_rotate(a, b);
		else
			ft_revrotate(a, b);
		tmp1 = *b;
	}
}
