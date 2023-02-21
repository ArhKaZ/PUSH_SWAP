/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:22:22 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 21:22:22 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	place_little_at_top_down(t_stack **stack_a, int value)
{
	int		down;
	t_stack	*first;

	first = *stack_a;
	down = 0;
	while (*stack_a != NULL)
	{
		if (value == (*stack_a)->value)
			break ;
		down++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first;
	return (down - 1);
}

int	place_little_at_top_up(t_stack **stack_a, int value)
{
	int		up;
	t_stack	*first;

	first = *stack_a;
	up = 0;
	*stack_a = stack_last(*stack_a);
	while (*stack_a != NULL)
	{
		if (value == (*stack_a)->value)
			break ;
		up++;
		*stack_a = (*stack_a)->before;
	}
	*stack_a = first;
	return (up);
}

int	place_little_at_bottom_down(t_stack **stack_b, int little)
{
	int		down;
	t_stack	*first;
	t_stack	*last;

	first = *stack_b;
	down = 0;
	last = stack_last(*stack_b);
	while ((*stack_b)->value != little)
		*stack_b = (*stack_b)->next;
	while ((*stack_b)->value != last->value)
	{
		down++;
		*stack_b = (*stack_b)->next;
	}
	*stack_b = first;
	return (down);
}

int	place_little_at_bottom_up(t_stack **stack_b, int little)
{
	int		up;
	t_stack	*first;
	t_stack	*last;

	first = *stack_b;
	up = 0;
	last = stack_last(*stack_b);
	while ((*stack_b)->value != little)
		*stack_b = (*stack_b)->next;
	while ((*stack_b)->value != last->value)
	{
		if ((*stack_b)->value == first->value)
		{
			up += 1;
			break ;
		}
		up++;
		*stack_b = (*stack_b)->before;
	}
	return (up);
}
