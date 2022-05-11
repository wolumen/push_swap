/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpreissn <jpreissn@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 13:45:02 by jpreissn          #+#    #+#             */
/*   Updated: 2022/02/07 13:45:02 by jpreissn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>

# define STACK_EMPTY LONG_MIN

typedef struct node_s {
	long			value;
	struct node_s	*next;
	struct node_s	*previous;
}				t_node;

typedef t_node	*t_stack;

long	init_stack_a(t_stack *stack_a, t_stack *stack_b, int argc, char **argv);
bool	push(t_stack *head, long value);
long	pop(t_stack *head);
void	del_stack(t_stack *head);
int		stack_size(t_stack *head);
bool	check_sorted(t_stack *head);

bool	ft_is_number(char *str);
long	ft_atoi(char *str);
bool	not_in_stack(t_stack *head, long value);
void	stay_positive(t_stack *stack_a);
long	find_min(t_stack *head);
long	find_max(t_stack *head);
bool	invert_rotation(t_stack *head, long min);

void	mv_pb(t_stack *stack_a, t_stack *stack_b);
void	mv_pa(t_stack *stack_a, t_stack *stack_b);
void	mv_ra(t_stack *stack_a);
void	mv_rb(t_stack *stack_b);
void	mv_rr(t_stack *stack_a, t_stack *stack_b);
void	mv_rra(t_stack *stack_a);
void	mv_rrb(t_stack *stack_b);
void	mv_rrr(t_stack *stack_a, t_stack *stack_b);
void	mv_sa(t_stack *stack_a);
void	mv_sb(t_stack *stack_b);
void	mv_ss(t_stack *stack_a, t_stack *stack_b);

void	sort_three(t_stack *stack_a);
void	sort_small(t_stack *stack_a, t_stack *stack_b);
void	bucket_sort(t_stack *stack_a, t_stack *stack_b);

#endif