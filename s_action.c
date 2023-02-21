/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_action.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:52:31 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/06 14:18:41 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack_a, t_action *actions)
{
	int	temp;

	add_action_list(&actions, SA);
	if (!(stack_a->next == NULL || stack_a == NULL))
	{
		temp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = temp;
		temp = stack_a->chunk;
		stack_a->chunk = stack_a->next->chunk;
		stack_a->next->chunk = temp;
		temp = stack_a->index;
		stack_a->index = stack_a->next->index;
		stack_a->next->index = temp;
	}
}

void	sb(t_stack *stack_b, t_action *actions)
{
	int	temp;

	add_action_list(&actions, SB);
	if (!(stack_b->next == NULL || stack_b == NULL))
	{
		temp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = temp;
	}
}

void	ss(t_list_stack *stacks, t_action *actions)
{
	add_action_list(&actions, SS);
	sa(stacks->stack_a, actions);
	sb(stacks->stack_b, actions);
}
