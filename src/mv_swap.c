/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 09:01:57 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/10 09:01:57 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mv_swap(t_stack *head)
{
	t_node	*temp;

	temp = *head;
	*head = (*head)->next;
	temp->next = (*head)->next;
	temp->previous = *head;
	(*head)->previous = NULL;
	(*head)->next = temp;
}

void	mv_sa(t_stack *stack_a)
{
	mv_swap(stack_a);
	write(1, "sa\n", 3);
}

void	mv_sb(t_stack *stack_b)
{
	mv_swap(stack_b);
	write(1, "sb\n", 3);
}

void	mv_ss(t_stack *stack_a, t_stack *stack_b)
{
	mv_swap(stack_a);
	mv_swap(stack_b);
	write(1, "ss\n", 3);
}
