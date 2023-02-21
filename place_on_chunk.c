/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_on_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:48:02 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/06 13:44:24 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	chunk_max(t_list_stack *stacks)
{
	int		chunk_max;
	t_stack	*first;

	chunk_max = 0;
	first = stacks->stack_a;
	while (stacks->stack_a != NULL)
	{
		if (stacks->stack_a->chunk > chunk_max)
			chunk_max = stacks->stack_a->chunk;
		stacks->stack_a = stacks->stack_a->next;
	}
	stacks->stack_a = first;
	return (chunk_max);
}

void	place_on_chunk(t_list_stack *stacks, t_action *actions, int chunk)
{
	if (stacks->stack_a->value >= get_max_chunk(&stacks->stack_b, chunk))
		pb(stacks, actions);
	else if (stacks->stack_a->value < get_min_chunk(&stacks->stack_b, chunk))
	{
		pb(stacks, actions);
		rb(&stacks->stack_b, actions);
	}
	else
		place_in_the_middle(stacks, actions);
}
