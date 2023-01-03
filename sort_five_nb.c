/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:09:47 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/03 12:09:48 by syluiset         ###   ########.fr       */
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

void    push_little(t_stack **stack_a, t_stack **stack_b)
{
    int little;

    little = find_little(stack_a);
    if (little == 0)
        return (pb(stack_a, stack_b));
    if (little == 1)
        return (sa(*stack_a), pb(stack_a, stack_b));
    if (little == 2)
        return (ra(stack_a), ra(stack_a), pb(stack_a, stack_b));
    if (little == 3)
        return (rra(stack_a), rra(stack_a), pb(stack_a, stack_b));
    if (little == 4)
        return (rra(stack_a), pb(stack_a, stack_b));
}

void    sort_five(t_stack **stack_a, t_stack **stack_b)
{
    push_little(stack_a, stack_b);
    push_little(stack_a, stack_b);
    choose_sort_tec(stack_a);
    pa(stack_a, stack_b);
    pa(stack_a, stack_b);
}