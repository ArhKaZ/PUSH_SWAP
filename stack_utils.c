/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:32:24 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 19:17:45 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_empty_stack(void)
{
	t_stack	*stack_to_return;

	stack_to_return = malloc(sizeof(t_stack));
	if (!stack_to_return)
		return (NULL);
	stack_to_return->value = 0;
	stack_to_return->chunk = -1;
	stack_to_return->index = -1;
	stack_to_return->next = NULL;
	return (stack_to_return);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack_to, t_stack *new)
{
	t_stack	*temp;

	new->next = NULL;
	new->before = NULL;
	if (!stack_to || !new)
		return ;
	if (*stack_to != NULL)
	{
		temp = stack_last(*stack_to);
		new->before = temp;
		temp->next = new;
	}
	else
		*stack_to = new;
}

void	stack_add_front(t_stack **stack_to, t_stack *new)
{
	t_stack	*second;

	second = *stack_to;
	if (!stack_to || !new)
		return ;
	if (*stack_to != NULL)
	{
		new->before = NULL;
		new->next = *stack_to;
		*stack_to = new;
		second->before = *stack_to;
	}
	else
	{
		new->before = NULL;
		new->next = NULL;
		*stack_to = new;
	}
}

void	fill_stack(int stack[], int len, t_stack **stack_a)
{
	int		i;
	t_stack	*new;

	i = 0;
	while (i < len)
	{
		new = create_empty_stack();
		if (!new)
			return ;
		new->value = stack[i];
		stack_add_back(stack_a, new);
		i++;
	}
}
