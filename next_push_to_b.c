/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_to_push_b                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:32:12 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 20:32:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nb_move_down(t_stack **stack_a, int chunk)
{
	int		mouv_down;
	t_stack	*first;

	first = *stack_a;
	mouv_down = 0;
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->chunk == chunk)
			break ;
		mouv_down++;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = first;
	return (mouv_down - 1);
}

int	get_nb_move_up(t_stack **stack_a, int chunk)
{
	int		mouv_up;
	t_stack	*first;

	first = *stack_a;
	mouv_up = 0;
	*stack_a = stack_last(*stack_a);
	while ((*stack_a)->before != NULL)
	{
		if ((*stack_a)->chunk == chunk)
			break ;
		mouv_up++;
		*stack_a = (*stack_a)->before;
	}
	*stack_a = first;
	return (mouv_up);
}

t_stack	*next_push_to_b(t_stack **stack_a, int chunk, t_action *actions)
{
	int	mouv_down;
	int	mouv_up;

	mouv_down = get_nb_move_down(stack_a, chunk);
	mouv_up = get_nb_move_up(stack_a, chunk);
	if (mouv_down < mouv_up)
	{
		while (mouv_down >= 0)
		{
			mouv_down--;
			ra(stack_a, actions);
		}
	}
	else
	{
		while (mouv_up >= 0 || (*stack_a)->chunk != chunk)
		{
			mouv_up--;
			rra(stack_a, actions);
		}
	}
	return (*stack_a);
}
