/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:45:26 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/19 13:37:00 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_l(t_node *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

void	push(t_node **a, t_node **b, int i)
{
	t_node	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (i == 0)
		write(1, "pa\n", 3);
	else if (i == 1)
		write(1, "pb\n", 3);
}

void	swap(t_node **a, int i)
{
	t_node	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp->data = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = tmp->data;
	if (i == 0)
		write(1, "sa\n", 3);
	else if (i == 1)
		write(1, "sb\n", 3);
	free(tmp);
}

void	rotate(t_node **a, int i)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp1 = *a;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	tmp1->next = tmp;
	tmp->next = NULL;
	if (i == 1)
		write(1, "ra\n", 3);
	else if (i == 2)
		write(1, "rb\n", 3);
}

void	revrotate(t_node **a, int i)
{
	t_node	*tmp;
	t_node	*tmp1;

	if (!*a || !(*a)->next)
		return ;
	tmp1 = *a;
	tmp = *a;
	while (tmp1->next->next)
		tmp1 = tmp1->next;
	*a = tmp1->next;
	(*a)->next = tmp;
	tmp1->next = NULL;
	if (i == 1)
		write(1, "rra\n", 4);
	else if (i == 2)
		write(1, "rrb\n", 4);
}
