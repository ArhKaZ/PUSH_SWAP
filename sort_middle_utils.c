/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_middle_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:58:15 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/10 14:58:21 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    give_chunk(t_stack **stack_a, int len, int sort_tab[])
{
    int len_chunk;
    int chunk;
    int i;
    t_stack *first;

    first = *stack_a;
    i = 0;
    chunk = 0;
    len_chunk = len / 5;
    while (*stack_a != NULL)
    {
        if ((*stack_a)->chunk == -1 && (*stack_a)->value <= sort_tab[len_chunk - 1])
        {
            (*stack_a)->chunk = chunk;
            i++;
        }
        if (i == len / 5 && len_chunk + len / 5 <= len)
        {
            *stack_a = first;
            len_chunk += len / 5;
            chunk++;
            i = 0;
        }
        else
            *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
}

void    give_chunk_big(t_stack **stack_a, int len, int sort_tab[])
{
    int len_chunk;
    int chunk;
    int i;
    t_stack *first;

    first = *stack_a;
    i = 0;
    chunk = 0;
    len_chunk = len / 10;
    while (*stack_a != NULL)
    {
        if ((*stack_a)->chunk == -1 && (*stack_a)->value <= sort_tab[len_chunk - 1])
        {
            (*stack_a)->chunk = chunk;
            i++;
        }
        if (i == len / 10 && len_chunk + len / 10 <= len)
        {
            *stack_a = first;
            len_chunk += len / 10;
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