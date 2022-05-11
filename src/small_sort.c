/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 13:17:34 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/10 13:17:34 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack_a)
{
	long	max;
	t_node	*tail;

	max = find_max(stack_a);
	tail = *stack_a;
	while (!check_sorted(stack_a))
	{	
		while (tail->next)
			tail = tail->next;
		if (max == (*stack_a)->value)
			mv_ra(stack_a);
		else if (max == tail->value)
			mv_sa(stack_a);
		else
			mv_rra(stack_a);
	}
}

void	sort_small(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_size(stack_a) > 3)
	{
		if ((*stack_a)->value != find_min(stack_a))
		{			
			if (invert_rotation(stack_a, find_min(stack_a)))
				mv_rra(stack_a);
			else
				mv_ra(stack_a);
		}
		else
			mv_pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (*stack_b)
		mv_pa(stack_a, stack_b);
}
