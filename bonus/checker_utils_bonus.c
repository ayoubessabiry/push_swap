/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 09:22:10 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/13 17:50:47 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

void	get_help(t_node **a, t_node **b, char *s)
{
	if (!ft_strcmp(s, "rra\n"))
		revrotate(a, 0);
	else if (!ft_strcmp(s, "rrb\n"))
		revrotate(b, 0);
	else if (!ft_strcmp(s, "rrr\n"))
	{
		revrotate(a, 0);
		revrotate(b, 0);
	}
	else
		ft_error("Error\n");
}

void	sort_ins(t_node **a, t_node **b, char *s)
{
	if (!ft_strcmp(s, "sa\n"))
		swap(a, 2);
	else if (!ft_strcmp(s, "sb\n"))
		swap(b, 2);
	else if (!ft_strcmp(s, "ss\n"))
	{
		swap(a, 2);
		swap(b, 2);
	}
	else if (!ft_strcmp(s, "pb\n"))
		push(a, b, 2);
	else if (!ft_strcmp(s, "pa\n"))
		push(b, a, 2);
	else if (!ft_strcmp(s, "ra\n"))
		rotate(a, 0);
	else if (!ft_strcmp(s, "rb\n"))
		rotate(b, 0);
	else if (!ft_strcmp(s, "rr\n"))
	{
		rotate(a, 0);
		rotate(b, 0);
	}
	else
		get_help(a, b, s);
}
