/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 08:37:51 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/19 13:38:38 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	get_inst(t_node **a, t_node **b)
{
	char	*inst;

	inst = get_next_line(0);
	while (inst)
	{
		sort_ins(a, b, inst);
		free(inst);
		inst = get_next_line(0);
	}
}

void	print(t_node *a)
{
	while (a)
	{
		printf("| %d |\n",a->data);
		a = a->next;
	}
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	get_stack(&a, av);
	check_dup(a);
	get_inst(&a, &b);
	if (sorted(a) && !b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
