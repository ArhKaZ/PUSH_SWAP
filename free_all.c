/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:42:34 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/06 15:06:29 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	stackdelone(t_stack *stack)
{
	free(stack->before);
	free(stack->next);
	free(stack);
}

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tempnxt;

	temp = NULL;
	tempnxt = *stack;
	while (temp != NULL)
	{
		temp = tempnxt;
		tempnxt = temp->next;
		stackdelone(temp);
	}
	*stack = NULL;
}

void	free_stacks(t_list_stack *stacks)
{
	free_stack(&stacks->stack_a);
	free_stack(&stacks->stack_b);
}

void	actiondelone(t_action *action)
{
	free(action->before);
	free(action->next);
	free(action);
}

void	free_action(t_action **actions)
{
	t_action *temp;
	t_action *tempnxt;

	temp = NULL;
	tempnxt = *actions;
	while (temp != NULL)
	{
		temp = tempnxt;
		tempnxt = temp->next;
		actiondelone(temp);
	}
	actions = NULL;
}