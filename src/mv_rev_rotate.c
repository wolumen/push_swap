/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:35:20 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/09 20:35:20 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	mv_rotate(t_stack *head, int direction)
{
	t_node	*tail;

	tail = *head;
	while (tail->next)
		tail = tail->next;
	(*head)->previous = tail;
	tail->next = *head;
	if (direction > 0)
	{
		*head = (*head)->next;
		tail = tail->next;
	}
	else if (direction < 0)
	{
		*head = (*head)->previous;
		tail = tail->previous;
	}
	(*head)->previous = NULL;
	tail->next = NULL;
}

void	mv_rra(t_stack *stack_a)
{
	mv_rotate(stack_a, -1);
	write(1, "rra\n", 4);
}

void	mv_rrb(t_stack *stack_b)
{
	mv_rotate(stack_b, -1);
	write(1, "rrb\n", 4);
}

void	mv_rrr(t_stack *stack_a, t_stack *stack_b)
{
	mv_rotate(stack_a, -1);
	mv_rotate(stack_b, -1);
	write(1, "rrr\n", 4);
}
