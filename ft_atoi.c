/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aessabir <aessabir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 15:35:17 by aessabir          #+#    #+#             */
/*   Updated: 2022/03/16 16:16:41 by aessabir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(int *arr, int size)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static long long	check_range(long long n, int sign)
{
	n = n * sign;
	if (n <= 2147483647 && n >= -2147483648)
		return (n);
	else
		ft_error("Error\n");
	return (0);
}

static int	check_iss(char s)
{
	if (s == ' ' || s == '\n' || s == '\f' || s == '\r'
		|| s == '\t' || s == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(char *str)
{
	int			i;
	long long	n;
	int			sign;

	i = 0;
	n = 0;
	sign = 1;
	while (check_iss(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] < '0' || str[i] > '9')
		ft_error("Error\n");
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	if (str[i])
		ft_error("Error\n");
	return (check_range(n, sign));
}
