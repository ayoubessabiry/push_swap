/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 10:31:02 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/16 17:21:28 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_arr(t_node *a, int *lis, int max)
{
	int	*arr;
	int	*dup;
	int	s;
	int	i;
	int	j;

	j = 0;
	s = len_l(a);
	arr = malloc(sizeof(int) * max);
	if (!arr)
		return (0);
	dup = get_dup(a);
	i = s;
	while (--i >= 0)
	{
		if (lis[s - 1] == max)
		{
			arr[j++] = dup[i];
			max--;
		}
		s--;
	}
	free(dup);
	return (arr);
}

void	insert(t_node **head, int x)
{
	t_node	*tmp;
	t_node	*tmp1;

	tmp = (t_node *)malloc(sizeof(t_node));
	if (!tmp)
		return ;
	tmp1 = *head;
	tmp->data = x;
	tmp->next = NULL;
	if (*head == NULL)
	{
		*head = tmp;
		return ;
	}
	while (tmp1->next)
		tmp1 = tmp1->next;
	tmp1->next = tmp;
}

int	*longest(t_node *a, int s)
{
	int		*arr;
	t_node	*tmp;
	t_node	*tmp_j;
	int		i;
	int		j;

	i = 0;
	tmp = a->next;
	j = 0;
	arr = arr_get(s);
	while (i++ < s - 1)
	{
		j = 0;
		tmp_j = a;
		while (j < i)
		{
			if (tmp->data > tmp_j->data && arr[i] < arr[j] + 1)
				arr[i] = arr[j] + 1;
			j++;
			tmp_j = tmp_j->next;
		}
		tmp = tmp->next;
	}
	return (arr);
}

void	get_stack(t_node **a, char **av)
{
	int		i;
	int		j;
	int		x;
	char	**arg;

	i = 1;
	while (av[i])
	{
		j = 0;
		arg = ft_split(av[i++], ' ');
		if (!arg[0])
			ft_error("Error\n");
		while (arg[j])
		{
			x = ft_atoi(arg[j]);
			insert(a, x);
			free(arg[j]);
			j++;
		}
		free(arg);
	}
}

int	main(int ac, char **av)
{
	int		*arr;
	int		*lng;
	t_node	*a;
	t_node	*b;

	if (ac == 1)
		return (0);
	a = NULL;
	b = NULL;
	get_stack(&a, av);
	check_dup(a);
	if (len_l(a) <= 5)
		sort_min(&a, &b);
	else
	{
		find_min(&a);
		lng = longest(a, len_l(a));
		arr = get_arr(a, lng, get_max(lng, len_l(a)));
		push_to_b(&a, &b, arr, get_max(lng, len_l(a)));
		if (b)
			sort(&a, &b);
		find_min(&a);
	}
	return (0);
}
