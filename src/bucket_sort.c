/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bucket_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 13:42:23 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/14 13:42:23 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	back_to_a(t_stack *stack_a, t_stack *stack_b);
static void	fill_buckets(t_stack *stack_a, t_stack *stack_b, long min, long max);
static int	get_buckets(t_stack *stack_a);


void	bucket_sort(t_stack *stack_a, t_stack *stack_b)
{
	long	min;
	long	max;

	min = find_min(stack_a);
	max = find_max(stack_a);
	fill_buckets(stack_a, stack_b, min, max);
	back_to_a(stack_a, stack_b);
}

static void	fill_buckets(t_stack *stack_a, t_stack *stack_b, long min, long max)
{
	long	range;
	long	i;
	int		tracker;
	int		idx;

	range = ((max - min) / get_buckets(stack_a)) + 1;
	i = 0;
	idx = (get_buckets(stack_a) - 1) / 2;
	while (i <= idx)
	{
		tracker = stack_size(stack_a);
		while (tracker--)
		{
			if (((*stack_a)->value / range) == (idx - i))
			{	
				mv_pb(stack_a, stack_b);
				mv_rb(stack_b);
			}
			else if (((*stack_a)->value / range) == (idx + i + 1))
				mv_pb(stack_a, stack_b);
			else
				mv_ra(stack_a);
		}
		i++;
	}
}

static void	back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	long	max;

	max = find_max(stack_b);
	while (*stack_b)
	{	
		while (max != (*stack_b)->value)
		{
			if (invert_rotation(stack_b, max))
				mv_rrb(stack_b);
			else
				mv_rb(stack_b);
		}
		mv_pa(stack_a, stack_b);
		max = find_max(stack_b);
	}
}

static int	get_buckets(t_stack *stack_a)
{
	int	size;
	int	buckets;

	size = stack_size(stack_a);
	if (size <= 12)
		buckets = size / 4;
	else if (size <= 50)
		buckets = size / 12;
	else if (size <= 200)
		buckets = size / 13;
	else if (size <= 300)
		buckets = size / 24;
	else if (size <= 400)
		buckets = size / 25;
	else
		buckets = size / 28;
	if (buckets % 2)
		return (buckets + 1);
	else
		return (buckets);
}

// 9   -> 6/5
// 100 -> 8/9 Buckets
// 250 -> 10/11
// 350 -> 14
// 500 -> 17 Buckets