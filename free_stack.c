/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 14:42:34 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/05 15:03:18 by syluiset         ###   ########.fr       */
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