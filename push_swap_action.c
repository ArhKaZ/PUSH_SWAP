/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:10:18 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/06 14:26:32 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, t_action *actions)
{
	int temp;

	add_action_list(&actions, SA);
	if (!(stack_a->next == NULL || stack_a == NULL))
	{
		temp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = temp;
	}
}

void	sb(t_stack *stack_b, t_action *actions)
{
	int temp;

	add_action_list(&actions, SB);
	if (!(stack_b->next == NULL || stack_b == NULL))
	{
		temp = stack_b->value;
		stack_b->value = stack_b->next->value;
	stack_b->next->value = temp;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b, t_action *actions)
{
	add_action_list(&actions, SS);
	sa(stack_a, actions);
	sb(stack_b, actions);
}

void	pa(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
	t_stack *first;
	t_stack *temp;

	add_action_list(&actions, PA);
	if ((*stack_b)->next != NULL)
	{
		first = (*stack_b)->next;
		first->before = NULL;
	}
	else
		first = NULL;
	if (!(*stack_b == NULL))
	{
		temp = create_empty_stack();
		if (!temp)
			return ;
		temp->value = (*stack_b)->value;
		temp->next = NULL;
		temp->chunk = (*stack_b)->chunk;
		temp->index = (*stack_b)->index;
		stack_add_front(stack_a, temp);
		free((*stack_b));
		(*stack_b) = first;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
	t_stack *first;
	t_stack *temp;

	add_action_list(&actions, PB);
	first = (*stack_a)->next;
	first->before = NULL;
	if (!(*stack_a == NULL))
	{
		temp = create_empty_stack();
		if (!temp)
			return ;
		temp->value = (*stack_a)->value;
		temp->next = NULL;
        temp->chunk = (*stack_a)->chunk;
        temp->index = (*stack_a)->index;
		stack_add_front(stack_b, temp);
		free((*stack_a));
		(*stack_a) = first;
	}
}

void	ra(t_stack **stack_a, t_action *actions)
{
	t_stack *second;
	t_stack *first;

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
	t_stack *second;
	t_stack *first;

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

void	rr(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
	add_action_list(&actions, RR);
	ra(stack_a, actions);
	rb(stack_b, actions);
}

void	rra(t_stack **stack_a, t_action *actions)
{
	t_stack *first;
	t_stack *new_last;

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
	t_stack *first;
	t_stack *new_last;

	add_action_list(&actions, RRB);
	first = (*stack_b);
	*stack_b = stack_last(*stack_b);
	first->before = *stack_b;
	new_last = (*stack_b)->before;
	(*stack_b)->next = first;
	(*stack_b)->before = NULL;
	new_last->next = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
	add_action_list(&actions, RRR);
	rra(stack_a, actions);
	rrb(stack_b, actions);
}