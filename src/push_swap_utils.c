/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:43:27 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/08 21:43:27 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

bool	ft_is_number(char *str)
{
	if (!str)
		return (false);
	if (ft_strlen(str) == 1 && *str == '-')
		return (false);
	while (*str)
	{
		if ((*str < '0' || *str > '9') && *str != '-')
			return (false);
		str++;
	}
	return (true);
}

long	ft_atoi(char *str)
{
	int		i;
	long	value;
	char	*first;

	first = (char *)str;
	if (*str == '-')
		str++;
	i = 0;
	value = 0;
	while (*str)
	{
		if (i++)
			value *= 10;
		if ((*str >= '0') && (*str <= '9'))
			value += *str - '0';
		str++;
	}
	if (*first == '-')
		value *= -1;
	if (value < -2147483648 || value > 2147483647)
		exit (write(1, "Error\n", 6));
	return (value);
}

void	stay_positive(t_stack *stack_a)
{
	long	min;
	t_node	*temp;

	temp = *stack_a;
	min = find_min(stack_a);
	if (min < 0)
	{
		while (temp)
		{
			temp->value = temp->value + (min * -1);
			temp = temp->next;
		}
	}
}
