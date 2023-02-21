/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:26 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/06 16:02:59 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab_int(int stack[], int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (stack[j] > stack[i])
			{
				temp = stack[j];
				stack[j] = stack[i];
				stack[i] = temp;
			}
			else
				j++;
		}
		i++;
	}
	return (stack);
}

int	len_stack(t_stack **stack)
{
	int		len;
	t_stack	*first;

	len = 0;
	while ((*stack)->before != NULL)
		*stack = (*stack)->before;
	first = *stack;
	while (*stack != NULL)
	{
		len++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (len);
}

t_bool	compare_to_sort_tab(t_list_stack *sts)
{
	t_stack	*first;

	if (sts->stack_b != NULL)
		return (false);
	first = sts->stack_a;
	while (sts->stack_a->next != NULL)
	{
		if ((sts->stack_a)->value > (sts->stack_a)->next->value)
		{
			sts->stack_a = first;
			return (false);
		}
		sts->stack_a = (sts->stack_a)->next;
	}
	sts->stack_a = first;
	return (true);
}
