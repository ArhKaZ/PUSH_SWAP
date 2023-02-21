/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:53:50 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 19:22:05 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, t_action *actions)
{
	t_stack	*first;
	t_stack	*new_last;

	add_action_list(&actions, RRA);
	first = *stack_a;
	*stack_a = stack_last(*stack_a);
	first->before = *stack_a;
	new_last = (*stack_a)->before;
	(*stack_a)->next = first;
	(*stack_a)->before = NULL;
	new_last->next = NULL;
}

void	rrb(t_stack **stack_b, t_action *actions)
{
	t_stack	*first;
	t_stack	*new_last;

	add_action_list(&actions, RRB);
	first = (*stack_b);
	*stack_b = stack_last(*stack_b);
	first->before = *stack_b;
	new_last = (*stack_b)->before;
	(*stack_b)->next = first;
	(*stack_b)->before = NULL;
	new_last->next = NULL;
}

void	rrr(t_list_stack *stacks, t_action *actions)
{
	add_action_list(&actions, RRR);
	rra(&stacks->stack_a, actions);
	rrb(&stacks->stack_b, actions);
}
