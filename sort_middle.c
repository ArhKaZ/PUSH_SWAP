/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:18:11 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 21:18:11 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_list_stack *stacks, t_action *actions, int chunk)
{
	if (chunk != stacks->chunk_max)
		get_little_on_top(&stacks->stack_a, actions, chunk + 1);
	while (stacks->stack_b != NULL)
	{
		if ((stacks->stack_b)->value < stack_last(stacks->stack_b)->value)
		{
			rrb(&stacks->stack_b, actions);
			pa(stacks, actions);
		}
		else
			pa(stacks, actions);
	}
}

void	push_two_to_b(t_list_stack *stacks, t_action *actions, int chunk)
{
	while (stacks->stack_b == NULL || len_stack(&stacks->stack_b) != 2)
	{
		if (stacks->stack_a->chunk == chunk)
		{
			pb(stacks, actions);
			if (len_stack(&stacks->stack_b) == 2)
				break ;
		}
		if (stacks->stack_a->chunk != chunk)
		{
			if (len_chunk(&stacks->stack_a, chunk) == 0)
				return ;
			stacks->stack_a = next_push_to_b(&stacks->stack_a, chunk, actions);
		}
	}
	if (stacks->stack_b->value < stacks->stack_b->next->value)
		sb(stacks->stack_b, actions);
}

void	sort_less_than_ten(t_list_stack *sts, t_action *actions)
{
	int	chunk;

	chunk = 0;
	while (len_stack(&sts->stack_a) != 3)
	{
		if ((sts->stack_a)->chunk == chunk)
		{
			pb(sts, actions);
			chunk++;
		}
		else
			sts->stack_a = next_push_to_b(&sts->stack_a, chunk, actions);
	}
	choose_sort_tec(&sts->stack_a, actions);
	while (sts->stack_b != NULL)
		pa(sts, actions);
}

void	push_to_b(t_list_stack *sts, t_action *act)
{
	int	chunk;

	chunk = sts->chunk_max;
	if (len_stack(&sts->stack_a) <= 10)
	{
		sort_less_than_ten(sts, act);
		return ;
	}
	while (compare_to_sort_tab(sts) == false)
	{
		if (sts->stack_b == NULL)
			push_two_to_b(sts, act, chunk);
		if ((sts->stack_a)->chunk == chunk)
			place_on_chunk(sts, act, chunk);
		else
		{
			if (len_chunk(&sts->stack_a, chunk) == 0)
			{
				push_back(sts, act, chunk);
				chunk--;
			}
			else
				sts->stack_a = next_push_to_b(&sts->stack_a, chunk, act);
		}
	}
}
