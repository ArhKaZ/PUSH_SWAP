#include "push_swap.h"

void    sort_chunk_2(t_stack **stack, t_stack *first)
{
    int tab[2];
    int i;

    i = 0;
    while (i < 2)
    {
        tab[i] = (*stack)->value;
        i++;
        *stack = (*stack)->next;
    }
    *stack = first;
    if (tab[0] < tab[1])
        sb(*stack);
}

void    sort_chunk_3(t_stack **stack, t_stack *first)
{
    int tab[3];
    int i;

    i = 0;
    while (i < 3)
    {
        tab[i] = (*stack)->value;
        i++;
        *stack = (*stack)->next;
    }
    *stack = first;
    if (tab[1] < tab[0] && tab[1] < tab[2])
    {
        if (tab[0] < tab[2])
            rrb(stack);
        else
        {
            sb(*stack);
            rb(stack);
        }
    }
    if (tab[1] > tab[0] && tab[1] > tab[2])
    {
        if (tab[0] < tab[2])
            rb(stack);
        else
            sb(*stack);
    }
}

// void    sort_chunk(t_stack **stack)
// {
//     int len;
//     t_stack *first;

//     first = *stack;
//     if (len == 2)
//         sort_chunk_2(stack, first);
//     if (len == 3)
//         sort_chunk_3(stack, first);
// }