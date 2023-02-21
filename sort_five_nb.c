/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:37:33 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 19:37:33 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_little(t_stack **stack_a)
{
	t_stack	*first;
	int		value;
	int		i;

	first = *stack_a;
	i = 0;
	value = (*stack_a)->value;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->value < value)
			value = (*stack_a)->value;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first;
	while ((*stack_a)->value != value)
	{
		i++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first;
	return (i);
}

void	push_little_five(t_list_stack *stacks, t_action *actions, int little)
{
	if (little == 0)
		return (pb(stacks, actions));
	if (little == 1)
	{
		sa(stacks->stack_a, actions);
		return (pb(stacks, actions));
	}
	if (little == 2)
	{
		ra(&stacks->stack_a, actions);
		ra(&stacks->stack_a, actions);
		return (pb(stacks, actions));
	}
	if (little == 3)
	{
		rra(&stacks->stack_a, actions);
		rra(&stacks->stack_a, actions);
		return (pb(stacks, actions));
	}
	if (little == 4)
	{
		rra(&stacks->stack_a, actions);
		return (pb(stacks, actions));
	}
}

void	sort_five(t_list_stack *stacks, t_action *actions)
{
	int	little;

	little = find_little(&stacks->stack_a);
	push_little_five(stacks, actions, little);
	sort_four(stacks, actions);
	pa(stacks, actions);
}
