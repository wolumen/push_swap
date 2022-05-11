/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mv_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:41:39 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/09 16:41:39 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	mv_push(t_stack *dest, t_stack *src)
{	
	long	temp;

	temp = pop(src);
	if (temp == STACK_EMPTY)
		return (false);
	push(dest, temp);
	return (true);
}

void	mv_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (mv_push(stack_a, stack_b))
		write(1, "pa\n", 3);
}

void	mv_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (mv_push(stack_b, stack_a))
		write(1, "pb\n", 3);
}
