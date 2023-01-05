/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:09:47 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/05 16:50:13 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int     find_little(t_stack **stack_a)
{
    t_stack *first;
    int value;
    int i;

    first = *stack_a;
    i = 0;
    value = (*stack_a)->value;
    while (*stack_a != NULL)
    {
        if ((*stack_a)->value < value)
            value = (*stack_a)->value;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    while ((*stack_a)->value != value)
    {
        i++;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (i);
}

void    push_little(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
    int little;

    little = find_little(stack_a);
    if (little == 0)
        return (pb(stack_a, stack_b, actions));
    if (little == 1)
        return (sa(*stack_a, actions), pb(stack_a, stack_b, actions));
    if (little == 2)
        return (ra(stack_a, actions), ra(stack_a, actions), pb(stack_a, stack_b, actions));
    if (little == 3)
        return (rra(stack_a, actions), rra(stack_a, actions), pb(stack_a, stack_b, actions));
    if (little == 4)
        return (rra(stack_a, actions), pb(stack_a, stack_b, actions));
}

void    sort_five(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
    push_little(stack_a, stack_b, actions);
    push_little(stack_a, stack_b, actions);
    choose_sort_tec(stack_a, actions);
    pa(stack_a, stack_b, actions);
    pa(stack_a, stack_b, actions);
}