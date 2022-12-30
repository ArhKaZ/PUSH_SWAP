#include "push_swap.h"

void    sort_four(t_stack **stack_a, t_stack **stack_b)
{
    push_little(stack_a, stack_b);
    choose_sort_tec(stack_a);
    pa(stack_a, stack_b);
}