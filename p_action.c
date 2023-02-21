/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_action.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:10:18 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 19:23:02 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list_stack *stacks, t_action *actions)
{
	t_stack	*first;
	t_stack	*temp;

	add_action_list(&actions, PA);
	if ((stacks->stack_b)->next != NULL)
	{
		first = (stacks->stack_b)->next;
		first->before = NULL;
	}
	else
		first = NULL;
	if (!(stacks->stack_b == NULL))
	{
		temp = create_empty_stack();
		if (!temp)
			return ;
		temp->value = (stacks->stack_b)->value;
		temp->next = NULL;
		temp->chunk = (stacks->stack_b)->chunk;
		temp->index = (stacks->stack_b)->index;
		stack_add_front(&stacks->stack_a, temp);
		free(stacks->stack_b);
		(stacks->stack_b) = first;
	}
}

void	pb(t_list_stack *stacks, t_action *actions)
{
	t_stack	*first;
	t_stack	*temp;

	add_action_list(&actions, PB);
	first = (stacks->stack_a)->next;
	first->before = NULL;
	if (!(stacks->stack_a == NULL))
	{
		temp = create_empty_stack();
		if (!temp)
			return ;
		temp->value = (stacks->stack_a)->value;
		temp->next = NULL;
		temp->chunk = (stacks->stack_a)->chunk;
		temp->index = (stacks->stack_a)->index;
		stack_add_front(&stacks->stack_b, temp);
		free((stacks->stack_a));
		(stacks->stack_a) = first;
	}
}
