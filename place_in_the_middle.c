/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_in_the_middle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:47:24 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 19:47:24 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	place_middle_down(t_list_stack *sts)
{
	int		down;
	t_stack	*first;
	int		chunk;
	int		value;

	chunk = sts->stack_a->chunk;
	value = sts->stack_a->value;
	first = sts->stack_b;
	down = 0;
	while (sts->stack_b->chunk != chunk)
	{
		sts->stack_b = sts->stack_b->next;
		down++;
	}
	while (sts->stack_b != NULL)
	{
		if (value < sts->stack_b->value && value > sts->stack_b->next->value)
			break ;
		down++;
		sts->stack_b = sts->stack_b->next;
	}
	sts->stack_b = first;
	return (down);
}

int	place_middle_up(t_list_stack *sts)
{
	int		up;
	t_stack	*first;
	int		chunk;
	int		value;

	chunk = sts->stack_a->chunk;
	value = sts->stack_a->value;
	first = sts->stack_b;
	up = 0;
	sts->stack_b = stack_last(sts->stack_b);
	while (sts->stack_b->chunk != chunk)
	{
		sts->stack_b = sts->stack_b->before;
		up++;
	}
	while (sts->stack_b != NULL)
	{
		if (value > sts->stack_b->value && value < sts->stack_b->before->value)
			break ;
		up++;
		sts->stack_b = sts->stack_b->before;
	}
	sts->stack_b = first;
	return (up);
}

void	place_in_the_middle(t_list_stack *stacks, t_action *actions)
{
	int	up;
	int	down;

	up = place_middle_up(stacks);
	down = place_middle_down(stacks);
	if (up < down)
	{
		while (up >= 0)
		{
			rrb(&stacks->stack_b, actions);
			up--;
		}
	}
	else
	{
		while (down >= 0)
		{
			rb(&stacks->stack_b, actions);
			down--;
		}
	}
	pb(stacks, actions);
	get_little_on_bottom(&stacks->stack_b, actions, stacks->stack_b->chunk);
}
