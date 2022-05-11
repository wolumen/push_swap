/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:31:46 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/08 20:31:46 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push(t_stack *head, long value)
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if (!newnode)
		return (false);
	newnode->value = value;
	newnode->next = *head;
	newnode->previous = NULL;
	if (*head)
		(*head)->previous = newnode;
	*head = newnode;
	return (true);
}

long	pop(t_stack *head)
{
	long	value;
	t_node	*temp;

	temp = *head;
	if (*head == NULL)
		return (STACK_EMPTY);
	value = (*head)->value;
	(*head) = (*head)->next;
	if (*head != NULL)
		(*head)->previous = NULL;
	free(temp);
	return (value);
}

void	del_stack(t_stack *head)
{
	long	value;

	value = 0;
	while (value != STACK_EMPTY)
		value = pop(head);
}

bool	check_sorted(t_stack *head)
{
	t_node	*temp;

	temp = *head;
	if (temp == NULL)
		return (true);
	while (temp->next)
	{
		if (temp->value > temp->next->value)
			return (false);
		temp = temp->next;
	}
	return (true);
}
