/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:26 by syluiset          #+#    #+#             */
/*   Updated: 2022/12/09 21:05:54 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	sa(t_stack *stack_a)
{
	int temp;

	if (!(stack_a->next == NULL || stack_a == NULL))
	{
		temp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = temp;
	}
}

void	sb(t_stack *stack_b)
{
	int temp;

	if (!(stack_b->next == NULL || stack_b == NULL))
	{
		temp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = temp;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!(stack_b == NULL))
	{
		stack_a->value = stack_b->value;
		free(stack_b);
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	if (!(stack_a == NULL))
	{
		stack_b->value = stack_a->value;
		free(stack_a);
	}
}

void	ra(t_stack *stack_a)
{
	t_stack *second;
	t_stack *first;

	first = stack_a;
	second = stack_a->next;
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	stack_a->next = second;
	first->next = NULL;
}

void	rb(t_stack *stack_b)
{
	t_stack *second;
	t_stack *first;

	first = stack_b;
	second = stack_b->next;
	while (stack_b->next != NULL)
		stack_b = stack_b->next;
	stack_b->next = second;
	first->next = NULL;
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack *stack_a)
{
	t_stack *first;

	first = stack_a;
	while (stack_a->next != NULL)
		stack_a = stack_a->next;
	stack_a->next = first;
}

void	rrb(t_stack *stack_b)
{
	t_stack *first;

	first = stack_b;
	while (stack_b->next != NULL)
		stack_b = stack_b->next;
	stack_b->next = first;
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}