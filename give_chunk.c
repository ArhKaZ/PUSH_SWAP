#include "push_swap.h"
int		stack_is_split(t_stack **stack)
{
    t_stack *first;

    first = *stack;
    while (*stack != NULL)
    {
        if ((*stack)->pos_mid == 0)
        {
            *stack = first;
            return 0;
        }
        *stack = (*stack)->next;
    }
    *stack = first;
    return (1);
}

void	split_at_mid(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first;
    int test;

    test = 0;
    first = *stack_a;
    while (test == 0)
    {
        if ((*stack_a)->pos_mid == 0)
        {
            pb(stack_a, stack_b);
            if (len_stack(stack_b) > 1)
            {
                if ((*stack_b)->value < (*stack_b)->next->value)
                    rb(stack_b);
            }
        }
        else
            ra(stack_a);
        test = stack_is_split(stack_a);
    }
    *stack_a = first;
}

void	put_pivot(t_stack **stack, int mid)
{
    t_stack *first;

    first = *stack;
    while (*stack != NULL)
    {
        if (((*stack)->value) >= mid)
            (*stack)->pos_mid = 1;
        if (((*stack)->value) < mid)
            (*stack)->pos_mid = 0;
        *stack = (*stack)->next;
    }
    *stack = first;
}
int     chunk_are_good(t_stack *stack)
{
    t_stack *first;

    first = stack;
    while (stack != NULL)
    {
        if (stack->index_chunk > 3 || stack->index_chunk == -1)
            return (0);
        stack= stack->next;
    }
    stack = first;
    return (1);
}
void change_chunk(t_stack **stack, t_stack *first, int chunk)
{
    *stack = first;
    int nb;

    nb = 0;
    while (*stack != NULL)
    {
        if ((*stack)->chunk == chunk)
        {
            (*stack)->index_chunk = nb;
            nb ++;
        }
        *stack = (*stack)->next;
    }
    *stack = first;
}

int		len_chunk(t_stack *stack, t_stack *first, int chunk)
{
    int len;

    stack = first;
    len = 0;
    while (stack != NULL)
    {
        if (stack->chunk == chunk)
            len++;
        stack = stack->next;
    }
    stack = first;
    return (len);
}

void	split_in_chunk(t_stack **stack)
{
    t_stack *first;
    int len;
    int chunk;

    first = *stack;
    while (*stack != NULL)
    {
        if ((*stack)->chunk == -1)
        {
            (*stack)->chunk = 0;
            (*stack)->index_chunk = len_chunk(*stack, first, (*stack)->chunk) - 1;
            *stack = first;
        }
        else
        {
            len = len_chunk(*stack, first, (*stack)->chunk);
            if (len > 3) {
                chunk = (*stack)->chunk;
                (*stack)->chunk += 1;
                (*stack)->index_chunk = len_chunk(*stack, first, (*stack)->chunk) - 1;
                change_chunk(stack, first, chunk);
                *stack = first;
            }
            else
                *stack = (*stack)->next;
        }
    }
    *stack = first;
}