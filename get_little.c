/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_little.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 12:34:52 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/10 15:13:10 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int get_min(t_stack **stack_a)
{
    int min;
    t_stack *first;

    first = *stack_a;
    min = (*stack_a)->value;
    while ((*stack_a) != NULL)
    {
        if ((*stack_a)->value < min)
            min = (*stack_a)->value;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (min);
}

int     place_little_down(t_stack **stack_a, int value)
{
    int down;
    t_stack *first;

    first = *stack_a;
    down = 0;
    while (*stack_a != NULL)
    {
        if (value == (*stack_a)->value)
            break;
        down++;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (down - 1);
}

int     place_little_up(t_stack **stack_a, int value)
{
    int up;
    t_stack *first;

    first = *stack_a;
    up = 0;
    *stack_a = stack_last(*stack_a);
    while (*stack_a != NULL)
    {
        if (value == (*stack_a)->value)
            break;
        up++;
        *stack_a = (*stack_a)->before;
    }
    *stack_a = first;
    return (up);
}

int		get_less_action_little(t_stack **stack_a)
{
	int little;
    int down;
    int up;

    little = get_min(stack_a);
    down = place_little_down(stack_a, little);
    up = place_little_up(stack_a, little);
	if (up < down)
		return (up);
	else
		return (down);
}


void    get_little_on_top(t_stack **stack_a, t_action *actions)
{
    int little;
    int down;
    int up;

    little = get_min(stack_a);
    down = place_little_down(stack_a, little);
    up = place_little_up(stack_a, little);
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
}