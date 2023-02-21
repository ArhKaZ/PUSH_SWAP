/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:42:34 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/20 12:16:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*tempnxt;

	temp = NULL;
	tempnxt = *stack;
	while (tempnxt != NULL)
	{
		temp = tempnxt;
		tempnxt = temp->next;
		free(temp);
	}
	*stack = NULL;
}

t_action	*del_one_action(t_action *actions)
{
	t_action	*before;
	t_action	*next;

	before = actions->before;
	next = actions->next;
	free(actions);
	before->next = next;
	if (next != NULL)
		next->before = before;
	actions = before;
	return (actions);
}

void	free_stacks(t_list_stack *stacks)
{
	free_stack(&stacks->stack_a);
	free_stack(&stacks->stack_b);
	free(stacks);
}

void	free_action(t_action **actions, t_action *first)
{
	t_action	*temp;
	t_action	*tempdel;

	*actions = first;
	temp = *actions;
	while (temp != NULL)
	{
		tempdel = temp;
		temp = temp->next;
		free(tempdel);
	}
	actions = NULL;
	free(actions);
}
