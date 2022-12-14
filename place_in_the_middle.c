/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_in_the_middle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:03:58 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/10 15:06:48 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     place_middle_down(t_stack **stack_a, int value, int chunk)
{
    int down;
    t_stack *first;

    first = *stack_a;
    down = 0;
    while ((*stack_a)->chunk != chunk)
    {
        *stack_a = (*stack_a)->next;
        down++;
    }
    while (*stack_a != NULL)
    {
        if (value > (*stack_a)->value && value < (*stack_a)->next->value)
        {
            down++;
            break;
        }
        down++;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (down - 1);
}

int     place_middle_up(t_stack **stack_a, int value, int chunk)
{
    int up;
    t_stack *first;

    first = *stack_a;
    up = 0;
    *stack_a = stack_last(*stack_a);
    while ((*stack_a)->chunk != chunk)
    {
        *stack_a = (*stack_a)->before;
        up++;
    }
    while (*stack_a != NULL)
    {
        if (value < (*stack_a)->value && value > (*stack_a)->before->value)
            break;
        up++;
        *stack_a = (*stack_a)->before;
    }
    *stack_a = first;
    return (up);
}

void  should_place_little(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
    t_stack *last;
    int value;

    if (*stack_b != NULL)
    {
        value = (*stack_b)->value;
        last = stack_last(*stack_a);
        if (value < (*stack_a)->value && value > last->value)
            pa(stack_a, stack_b, actions);
    }
}

void    place_in_the_middle(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
    int up;
    int down;

    up = place_middle_up(stack_a, (*stack_b)->value, (*stack_b)->chunk);
    down = place_middle_down(stack_a, (*stack_b)->value,  (*stack_b)->chunk);
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
    pa(stack_a, stack_b, actions);
    should_place_little(stack_a, stack_b, actions); //TODO a regarder
    get_little_on_top(stack_a, actions);
}
