/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:26 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/10 14:55:15 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*sort_tab_int(int stack[], int len)
{
	int i;
	int j;
	int temp;

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

void	repeat_x_time(t_stack **stack, t_action *actions, void (*action)(t_stack **, t_action *), int time)
{
	while (time > 0)
	{
		action(stack, actions);
		time--;
	}
}

int		len_stack(t_stack **stack)
{
	int len;
	t_stack *first;

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

t_bool  compare_to_sort_tab(t_stack **stack_a, int sort_tab[], int len)
{
    int i;
    t_stack *first;

    first = *stack_a;
    i = 0;
    while (i < len)
    {
        if (sort_tab[i] != (*stack_a)->value) {
            *stack_a = first;
            return (false);
        }
        i++;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (true);
}