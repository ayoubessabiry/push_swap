/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 14:12:51 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/13 16:27:18 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rot(t_node *a, int b)
{
	t_node	*tmp;
	int		j;
	int		last;

	j = 0;
	tmp = a;
	while (tmp)
	{
		last = get_last(&a);
		if ((b > tmp->data && !tmp->next)
			|| (b > tmp->data && b < tmp->next->data))
		{
			j++;
			break ;
		}
		else if (b < tmp->data && b > last)
			break ;
		j++;
		tmp = tmp->next;
	}
	return (j);
}

int	ft_rev(t_node *a, int b, int j)
{
	int		*dup;
	int		i;
	t_node	*tmp;

	tmp = a;
	i = 0;
	dup = malloc(sizeof(int) * len_l(a));
	if (!dup)
		return (0);
	while (tmp)
	{
		dup[i++] = tmp->data;
		tmp = tmp->next;
	}
	while (i)
	{
		if (b > dup[i-- - 1] && b < dup[0])
			break ;
		j++;
	}
	free(dup);
	return (j);
}

void	get_b(t_node **b, int res)
{
	t_node	*tmp;

	tmp = *b;
	while (tmp && tmp->data != res)
	{
		tmp = tmp->next;
		rotate (b, 2);
	}
}

void	helper(t_node *a, int b, int *j)
{
	if (ft_rot(a, b) <= (len_l(a) / 2))
		*j += ft_rot(a, b);
	else if (ft_rot(a, b) == len_l(a))
	{
		if (check_if_max(a, b))
			*j += find_max_a(a);
		else
			*j += find_min_a(a);
	}
	else
		*j += ft_rev(a, b, *j);
}

int	check_push(t_node *a, t_node **b)
{
	t_node	*tmp;
	int		res;
	int		i;
	int		j;
	int		min;

	i = 0;
	min = 2147483647;
	tmp = *b;
	while (tmp)
	{	
		j = i;
		helper(a, tmp->data, &j);
		if (j < min)
		{
			min = j;
			res = tmp->data;
		}
		tmp = tmp->next;
		i++;
	}
	get_b(b, res);
	return (min);
}
