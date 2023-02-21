/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_action.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:55:25 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 19:22:20 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a, t_action *actions)
{
	t_stack	*second;
	t_stack	*first;

	add_action_list(&actions, RA);
	first = (*stack_a);
	second = (*stack_a)->next;
	second->before = NULL;
	*stack_a = stack_last((*stack_a));
	first->next = NULL;
	first->before = *stack_a;
	(*stack_a)->next = first;
	*stack_a = second;
}

void	rb(t_stack **stack_b, t_action *actions)
{
	t_stack	*second;
	t_stack	*first;

	add_action_list(&actions, RB);
	first = (*stack_b);
	second = (*stack_b)->next;
	second->before = NULL;
	(*stack_b) = stack_last(*stack_b);
	first->next = NULL;
	first->before = *stack_b;
	(*stack_b)->next = first;
	(*stack_b) = second;
}

void	rr(t_list_stack *stacks, t_action *actions)
{
	add_action_list(&actions, RR);
	ra(&stacks->stack_a, actions);
	rb(&stacks->stack_b, actions);
}
