/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:09:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/05 16:50:50 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_little_in_chunk(t_stack **stack_a,t_stack **stack_b, int chunk, t_action *actions)
{
    t_stack *first;
    int value;

    first = *stack_a;
    value = first->value;
    while (*stack_a != NULL)
    {
        if ((*stack_a)->chunk == chunk && (*stack_a)->value < value)
            value = (*stack_a)->value;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    while ((*stack_a)->value != value)
        ra(stack_a, actions);
    pb(stack_a, stack_b, actions);
}
int     get_nb_move_down(t_stack **stack_a, int chunk)
{
    int mouv_down;
    t_stack *first;

    first = *stack_a;
    mouv_down = 0;
    while ((*stack_a)->next != NULL)
    {
        if ((*stack_a)->chunk == chunk)
            break;
        mouv_down++;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (mouv_down - 1);
}

int     get_nb_move_up(t_stack **stack_a, int chunk)
{
    int mouv_up;
    t_stack *first;

    first = *stack_a;
    mouv_up = 0;
    *stack_a = stack_last(*stack_a);
    while((*stack_a)->before != NULL)
    {
        if ((*stack_a)->chunk == chunk)
            break;
        mouv_up++;
        *stack_a = (*stack_a)->before;
    }
    *stack_a = first;
    return (mouv_up);
}

t_stack *next_push_to_b(t_stack **stack_a, int chunk, t_action *actions)
{
    int mouv_down;
    int mouv_up;

    mouv_down = get_nb_move_down(stack_a, chunk);
    mouv_up = get_nb_move_up(stack_a, chunk);
    if (mouv_down < mouv_up)
    {
        while (mouv_down >= 0)
        {
            mouv_down--;
            ra(stack_a, actions);
        }
    }
    else
    {
        while (mouv_up >= 0 || (*stack_a)->chunk != chunk)
        {
            mouv_up--;
            rra(stack_a, actions);
        }
    }
    return (*stack_a);
}

int		len_l_chunk(t_stack **stack, int l_chunk)
{
    int len;
    t_stack *first;

    first = *stack;
    len = 0;
    while (*stack != NULL)
    {
        if ((*stack)->index == l_chunk)
            len++;
        *stack = (*stack)->next;
    }
    *stack = first;
    return (len);
}

int     get_middle_value(t_stack **stack, int chunk)
{
    int value;
    int *tab;
    int i;
    t_stack *first;

    i = 0;
    first = *stack;
    value = len_chunk(stack, chunk);
    tab = malloc(sizeof(int) * value);
    while (i < value)
    {
        if ((*stack)->chunk == chunk)
        {
            tab[i] = (*stack)->value;
            i++;
        }
        *stack = (*stack)->next;
    }
    sort_tab_int(tab, value);
    value = tab[value / 2];
    free(tab);
    *stack = first;
    return (tab[value / 2]);
}


int *index_in_tab(t_stack **stack, int chunk)
{
    t_stack *first;
    int *tab;
    int len;
    int i;

    i = 0;
    len = len_chunk(stack, chunk);
    first = *stack;
    tab = malloc(sizeof(int) * len);
    while (*stack != NULL)
    {
        tab[i] = (*stack)->value;
        i++;
        *stack = (*stack)->next;
    }
    *stack = first;
    return (tab);
}

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

void    get_little_on_top(t_stack **stack_a, t_action *actions)
{
    int little;
    int down;
    int up;

    little = get_min(stack_a);
    down = place_little_down(stack_a, little);
    up = place_little_up(stack_a, little);
    //!ft_printf("[little :%d/down :%d/up :%d]\n", little, down, up);
    //!print_stack(*stack_a);
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
    should_place_little(stack_a, stack_b, actions);
    get_little_on_top(stack_a, actions);
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

void    place_on_chunk(t_stack **stack_a, t_stack **stack_b, t_action *actions) //?mettre au dessous de la moitier en dessous
{
    int iter;
    iter = 0;
    if ((*stack_a)->index % 2 == 0)
    {
        if (len_stack(stack_b) == 1)
        {
            pb(stack_a, stack_b, actions);
            rb(stack_b, actions);
        }
        else
        {
            while ((*stack_a)->value < stack_last(*stack_b)->value)
            {
                rrb(stack_b, actions);
                iter++;
            }
            pb(stack_a, stack_b, actions);
            while (iter >= 0)
            {
                rb(stack_b, actions);
                iter--;
            }
        }
    }
    else
    {
        if (len_stack(stack_b) == 1)
            pb(stack_a, stack_b, actions);
        else
        {
            while ((*stack_a)->value < (*stack_b)->value)
            {
                rb(stack_b, actions);
                iter++;
            }
            pb(stack_a, stack_b, actions);
            while (iter > 0)
            {
                rrb(stack_b, actions);
                iter--;
            }
        }
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
        {
            place_on_chunk(&stacks->stack_a, &stacks->stack_b, actions);
        }
        else
        {
            if (len_chunk(&stacks->stack_a, chunk) == 0)
                chunk++;
            else
                stacks->stack_a = next_push_to_b(&stacks->stack_a, chunk, actions);
        }
    }
}

void    give_chunk(t_stack **stack_a, int len, int sort_tab[])
{
    int len_chunk;
    int chunk;
    int i;
    t_stack *first;

    first = *stack_a;
    i = 0;
    chunk = 0;
    len_chunk = 20 * len/ 100;
    while (*stack_a != NULL)
    {
        if ((*stack_a)->chunk == -1 && (*stack_a)->value <= sort_tab[len_chunk - 1])
        {
            (*stack_a)->chunk = chunk;
            i++;
        }
        if (i == 20 * len / 100 && len_chunk + 20 * len / 100 <= len)
        {
            *stack_a = first;
            len_chunk += 20 * len / 100;
            chunk++;
            i = 0;
        }
        else
            *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
}

void    re_index(t_stack **stack_a, int sort_tab[], int len)
{
    int i;
    t_bool test;
    t_stack *first;

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
                break;
            }
            i++;
        }
        *stack_a = (*stack_a)->next;
        if (*stack_a == NULL)
            test = true;
    }
    *stack_a = first;
}

void    sort_middle_stack(t_list_stack *stacks, int len, int sort_tab[], t_action *actions)
{
    give_chunk(&stacks->stack_a, len, sort_tab);
    re_index(&stacks->stack_a, sort_tab, len);
    push_to_b(stacks, actions);
    choose_sort_tec(&stacks->stack_a, actions);
    push_back(&stacks->stack_a, &stacks->stack_b, actions);
}