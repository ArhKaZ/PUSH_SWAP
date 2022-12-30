#include "push_swap.h"
void    sort_case_four(t_stack **stack)
{
    sa(*stack);
    ra(stack);
}

void    sort_case_two(t_stack **stack)
{
    sa(*stack);
    rra(stack);
}

void    choose_sort_tec(t_stack **stack)
{
    int tab[3];
    int i;
    t_stack *first = *stack;
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
            sa(*stack); //case 1
        else
            ra(stack); //case 3
    }
    if (tab[1] > tab[0] && tab[1] > tab[2])
    {
        if (tab[0] < tab[2])
            sort_case_four(stack); //case 4
        else
            rra(stack); //case 5
    }
    if (tab[1] < tab[0] && tab[1] > tab[2])
        sort_case_two(stack); //case2
}