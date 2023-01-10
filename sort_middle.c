/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:09:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/10 15:12:33 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_max_chunk(t_stack **stack_a, int chunk)
{
    int max;
    t_stack *first;

    (void)chunk;
    first = *stack_a;
    max = (*stack_a)->value;
    while ((*stack_a) != NULL)
    {
        if (max < (*stack_a)->value)
            max = (*stack_a)->value;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (max);
}

int get_min_chunk(t_stack **stack_a, int chunk)
{
    int min;
    t_stack *first;

    first = *stack_a;
    min = (*stack_a)->value;
    while ((*stack_a)->next != NULL)
    {
        if ((*stack_a)->chunk == chunk && (*stack_a)->value < min)
            min = (*stack_a)->value;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (min);
}

void    push_back(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
    int chunk;

    chunk = 4;
    while (*stack_b != NULL)
    {
        if ((*stack_b)->value < stack_last(*stack_b)->value)
            rrb(stack_b, actions);
        if (len_chunk(stack_b, chunk) == 0)
        {
            pa(stack_a, stack_b, actions);
            chunk--;
        }
        else if ((*stack_b)->value > get_max_chunk(stack_a, chunk))
        {
            pa(stack_a, stack_b, actions);
            ra(stack_a, actions);
        }
        else if ((*stack_b)->value < get_min_chunk(stack_a, chunk))
            pa(stack_a, stack_b, actions);
        else
            place_in_the_middle(stack_a, stack_b, actions);
    }
}

void    push_to_b(t_list_stack *stacks, t_action *actions)
{
    int chunk;

    chunk = 0;
    while (len_stack(&stacks->stack_a) > 3)
    {
        if (stacks->stack_b == NULL)
        {
            get_little_on_top(&stacks->stack_a, actions);
            pb(&stacks->stack_a, &stacks->stack_b, actions);
        }
        if ((stacks->stack_a)->chunk == chunk)
            place_on_chunk(&stacks->stack_a, &stacks->stack_b, actions);
        else
        {
            if (len_chunk(&stacks->stack_a, chunk) == 0)
                chunk++;
            else
                stacks->stack_a = next_push_to_b(&stacks->stack_a, chunk, actions);
        }
    }
}
