/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:09:56 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/03 19:02:43 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_little_in_chunk(t_stack **stack_a,t_stack **stack_b, int chunk)
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
        ra(stack_a);
    pb(stack_a, stack_b);
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

t_stack **next_push_to_b(t_stack **stack_a, int chunk)
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
            ra(stack_a);
        }
    }
    else
    {
        while (mouv_up >= 0 || (*stack_a)->chunk != chunk)
        {
            mouv_up--;
            rra(stack_a);
        }
    }
    return (stack_a);
}

int		len_l_chunk(t_stack **stack, int l_chunk)
{
    int len;
    t_stack *first;

    first = *stack;
    len = 0;
    while (*stack != NULL)
    {
        if ((*stack)->l_chunk == l_chunk)
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
        if (i == 20 * len / 100 && len_chunk + 20 * len / 100 <= len) {
            *stack_a = first;
            len_chunk += len / 5;
            chunk++;
            i = 0;
        }
        else
            *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    print_chunk_and_index(*stack_a);
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

int     place_middle_down(t_stack **stack_b, int value, int chunk)
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

void    get_little_on_top(t_stack **stack_a)
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
                rra(stack_a);
                up--;
            }
    }
    else
    {
        while (down >= 0)
        {
            ra(stack_a);
            down--;
        }
    }
}

void  should_place_little(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *last;
    int value;

    if (*stack_b != NULL)
    {
        value = (*stack_b)->value;
        last = stack_last(*stack_a);
        if (value < (*stack_a)->value && value > last->value)
            pa(stack_a, stack_b);
    }
}

void    place_in_the_middle(t_stack **stack_a, t_stack **stack_b)
{
    int up;
    int down;

    up = place_middle_up(stack_a, (*stack_b)->value, (*stack_b)->chunk);
    down = place_middle_down(stack_a, (*stack_b)->value,  (*stack_b)->chunk);
    if (up < down)
    {
        while (up >= 0)
        {
            rra(stack_a);
            up--;
        }
    }
    else
    {
        while (down >= 0)
        {
            ra(stack_a);
            down--;
        }
    }
    pa(stack_a, stack_b);
    should_place_little(stack_a, stack_b);
    get_little_on_top(stack_a);
}

void    push_back(t_stack **stack_a, t_stack **stack_b)
{
    int chunk;

    chunk = 4;
    while (*stack_b != NULL)
    {
        if (len_chunk(stack_b, chunk) == 0)
        {
            pa(stack_a, stack_b);
            chunk--;
        }
        if ((*stack_b)->value > get_max_chunk(stack_a, chunk))
        {
            pa(stack_a, stack_b);
            ra(stack_a);
        }
        else if ((*stack_b)->value < get_min_chunk(stack_a, chunk))
            pa(stack_a, stack_b);
        else
            place_in_the_middle(stack_a, stack_b);
    }
}

void    place_on_chunk(t_stack **stack_a, t_stack **stack_b, int chunk) //?mettre au dessous de la moitier en dessous
{
    if ((*stack_a)->value > get_max_chunk(stack_b, chunk))
            pb(stack_a, stack_b);
        else if ((*stack_a)->value < get_min_chunk(stack_b, chunk))
        {
            pb(stack_a, stack_b);
            ra(stack_a);
        }
        else
            place_in_the_middle(stack_a, stack_b);
}

void    push_to_b(t_stack **stack_a, t_stack **stack_b)
{
    //!t_stack *first;
    int chunk;

    chunk = 0;
    while (len_stack(stack_a) > 3)
    {
        //!print_chunk_and_index(*stack_a);
        if ((*stack_a)->chunk == chunk)
            place_on_chunk(stack_a, stack_b, chunk);
        else
        {
            if (len_chunk(stack_a, chunk) == 0)
                chunk++;
            else
                //!ra(stack_a);
                stack_a = next_push_to_b(stack_a, chunk);
        }
    }
}

void    sort_middle_stack(t_stack **stack_a, t_stack **stack_b, int len, int sort_tab[])
{
    give_chunk(stack_a, len, sort_tab);
    push_to_b(stack_a, stack_b);
    choose_sort_tec(stack_a);
    push_back(stack_a, stack_b);
}