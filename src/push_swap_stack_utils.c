/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 11:42:22 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/20 11:42:22 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	not_in_stack(t_stack *head, long value)
{
	t_node	*temp;

	temp = *head;
	while (temp)
	{
		if (temp->value == value)
			return (false);
		temp = temp->next;
	}
	return (true);
}

int	stack_size(t_stack *head)
{
	int		size;
	t_node	*tail;

	tail = *head;
	size = 0;
	while (tail)
	{
		tail = tail->next;
		size++;
	}
	return (size);
}

long	find_min(t_stack *head)
{
	long	value;
	t_node	*temp;

	temp = *head;
	if (temp == NULL)
		return (STACK_EMPTY);
	value = temp->value;
	while (temp)
	{
		if (value > temp->value)
			value = temp->value;
		temp = temp->next;
	}
	return (value);
}

long	find_max(t_stack *head)
{
	long	value;
	t_node	*temp;

	temp = *head;
	if (temp == NULL)
		return (STACK_EMPTY);
	value = temp->value;
	while (temp)
	{
		if (value < temp->value)
			value = temp->value;
		temp = temp->next;
	}
	return (value);
}

bool	invert_rotation(t_stack *head, long min)
{
	t_node	*temp;
	int		size;
	int		pos;

	size = stack_size(head);
	temp = (*head);
	pos = 0;
	while (min != temp->value)
	{
		temp = temp->next;
		pos++;
	}
	if (pos > (size / 2))
		return (true);
	else
		return (false);
}
