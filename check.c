/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 11:47:02 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/13 17:49:40 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(char *s)
{
	ft_putstr_fd(s, 2);
	exit(1);
}

int	check(t_node *a, int i)
{
	while (a)
	{
		if (a->data == i)
			return (0);
		a = a->next;
	}
	return (1);
}

void	get_min(t_node **a, int min, int pos, int i)
{
	t_node	*tmp;

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
			break ;
	}
}

void	find_min(t_node **a)
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
	get_min(a, min, pos, i);
}

void	check_dup(t_node *a)
{
	while (a)
	{
		if (!check(a->next, a->data))
			ft_error("Error\n");
		a = a->next;
	}
}
