/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 19:09:16 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 19:09:16 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	re_index(t_stack **stack_a, int sort_tab[], int len)
{
	int		i;
	t_bool	test;
	t_stack	*first;

	first = *stack_a;
	test = false;
	while (test == false)
	{
		i = 0;
		while (i < len)
		{
			if (sort_tab[i] == (*stack_a)->value)
			{
				(*stack_a)->index = i;
				break ;
			}
			i++;
		}
		*stack_a = (*stack_a)->next;
		if (*stack_a == NULL)
			test = true;
	}
	*stack_a = first;
}

int	len_chunk(t_stack **stack, int chunk)
{
	int		len;
	t_stack	*first;

	first = *stack;
	len = 0;
	while (*stack != NULL)
	{
		if ((*stack)->chunk == chunk)
			len++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (len);
}
