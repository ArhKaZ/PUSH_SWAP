/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_little.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:25:21 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 21:25:21 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_chunk(t_stack **stack_a, int chunk)
{
	long int	max;
	t_stack		*first;

	first = *stack_a;
	max = LONG_MIN;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->chunk == chunk && (*stack_a)->value > max)
			max = (*stack_a)->value;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first;
	return (max);
}

int	get_min_chunk(t_stack **stack_a, int chunk)
{
	long int	min;
	t_stack		*first;

	first = *stack_a;
	min = LONG_MAX;
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->chunk == chunk && (*stack_a)->value < min)
			min = (*stack_a)->value;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first;
	return (min);
}

void	get_little_on_top(t_stack **stack_a, t_action *actions, int chunk)
{
	int	little;
	int	down;
	int	up;

	little = get_min_chunk(stack_a, chunk);
	down = place_little_at_top_down(stack_a, little);
	up = place_little_at_top_up(stack_a, little);
	if (up < down)
	{
		while (up >= 0)
		{
			rra(stack_a, actions);
			up--;
		}
	}
	else
	{
		while (down >= 0)
		{
			ra(stack_a, actions);
			down--;
		}
	}
}

void	get_little_on_bottom(t_stack **stack_b, t_action *actions, int chunk)
{
	int	little;
	int	down;
	int	up;

	little = get_min_chunk(stack_b, chunk);
	down = place_little_at_bottom_down(stack_b, little);
	up = place_little_at_bottom_up(stack_b, little);
	if (up < down)
	{
		while (up > 0)
		{
			rb(stack_b, actions);
			up--;
		}
	}
	else
	{
		while (down > 0)
		{
			rrb(stack_b, actions);
			down--;
		}
	}
}
