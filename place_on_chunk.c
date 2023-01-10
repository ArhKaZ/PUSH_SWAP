/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_on_chunk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:48:02 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/10 14:59:39 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	place_on_chunk_even(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
    int iter;

    iter = 0;
	if (len_stack(stack_b) == 1)
	{
		pb(stack_a, stack_b, actions);
		rb(stack_b, actions);
	}
	else
	{
		while ((*stack_a)->value < stack_last(*stack_b)->value)
		{
			rrb(stack_b, actions);
			iter++;
		}
		pb(stack_a, stack_b, actions);
		while (iter >= 0)
		{
			rb(stack_b, actions);
			iter--;
		}
	}
}

void	place_on_chunk_odd(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
	int iter;

	iter = 0;
	if (len_stack(stack_b) == 1)
		pb(stack_a, stack_b, actions);
	else
	{
		while ((*stack_a)->value < (*stack_b)->value)
		{
			rb(stack_b, actions);
			iter++;
		}
		pb(stack_a, stack_b, actions);
		while (iter > 0)
		{
			rrb(stack_b, actions);
			iter--;
		}
	}
}

void    place_on_chunk(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
    if ((*stack_a)->index % 2 == 0)
        place_on_chunk_even(stack_a, stack_b, actions);
    else
        place_on_chunk_odd(stack_a, stack_b, actions);
}
