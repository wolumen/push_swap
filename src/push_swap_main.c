/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:20:14 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/08 20:20:14 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 3)
		return (0);
	if (init_stack_a(&stack_a, &stack_b, argc, argv) != 0)
		return (0);
	if (check_sorted(&stack_a))
		return (0);
	stay_positive(&stack_a);
	if (stack_size(&stack_a) <= 5)
		sort_small(&stack_a, &stack_b);
	else
		bucket_sort(&stack_a, &stack_b);
	del_stack(&stack_a);
	del_stack(&stack_b);
	return (0);
}

long	init_stack_a(t_stack *stack_a, t_stack *stack_b, int argc, char **argv)
{
	long	temp;

	while (argc != 1)
	{
		if (ft_is_number(argv[argc - 1]))
		{
			temp = ft_atoi(argv[argc - 1]);
			if (not_in_stack(stack_a, temp))
				push(stack_a, temp);
			else
			{
				del_stack(stack_a);
				del_stack(stack_b);
				return (write(1, "Error\n", 6));
			}
		}
		else
		{
			del_stack(stack_a);
			del_stack(stack_b);
			return (write(1, "Error\n", 6));
		}
		argc--;
	}
	return (0);
}
