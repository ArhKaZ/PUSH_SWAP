/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:46:34 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 19:46:34 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_little_four(t_list_stack *stacks, t_action *actions, int little)
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
		return (pb(stacks, actions));
	}
}

void	sort_four(t_list_stack *stacks, t_action *actions)
{
	int	little;

	little = find_little(&stacks->stack_a);
	push_little_four(stacks, actions, little);
	choose_sort_tec(&stacks->stack_a, actions);
	pa(stacks, actions);
}
