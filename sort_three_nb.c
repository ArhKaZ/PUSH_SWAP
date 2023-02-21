/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:18:16 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 19:18:16 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_four(t_stack **stack, t_action *actions)
{
	sa(*stack, actions);
	ra(stack, actions);
}

void	sort_case_two(t_stack **stack, t_action *actions)
{
	sa(*stack, actions);
	rra(stack, actions);
}

void	sort_tec(t_stack **stack, t_action *actions, int tab[3])
{
	if (tab[1] < tab[0] && tab[1] < tab[2])
	{
		if (tab[0] < tab[2])
			sa(*stack, actions);
		else
			ra(stack, actions);
	}
	if (tab[1] > tab[0] && tab[1] > tab[2])
	{
		if (tab[0] < tab[2])
			sort_case_four(stack, actions);
		else
			rra(stack, actions);
	}
	if (tab[1] < tab[0] && tab[1] > tab[2])
		sort_case_two(stack, actions);
}

void	choose_sort_tec(t_stack **stack, t_action *actions)
{
	int		tab[3];
	int		i;
	t_stack	*first;

	first = *stack;
	i = 0;
	while (i < 3)
	{
		tab[i] = (*stack)->value;
		i++;
		*stack = (*stack)->next;
	}
	*stack = first;
	sort_tec(stack, actions, tab);
}
