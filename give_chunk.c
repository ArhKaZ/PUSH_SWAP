#include "push_swap.h"

// int		stack_is_split(t_stack **stack, int pos)
// {
//     t_stack *first;

//     first = *stack;
//     while (*stack != NULL)
//     {
//         if ((*stack)->pos_mid == pos)
//         {
//             *stack = first;
//             return 0;
//         }
//         *stack = (*stack)->next;
//     }
//     *stack = first;
//     return (1);
// }
//void	split_at_mid(t_stack **stack_a, t_stack **stack_b, int pos)
//{
//    t_stack *first;
//    int test;
//
//    test = 0;
//    first = *stack_a;
//    while (test == 0)
//    {
//        if ((*stack_a)->pos_mid == pos)
//        {
//            print_chunk_and_index(*stack_b);
//            push_on_b(stack_a, stack_b);
//            print_chunk_and_index(*stack_b);
//            ft_printf("//\n");
//        }
//        else
//            ra(stack_a);
//        test = stack_is_split(stack_a, pos);
//    }
//}
// void	put_pivot(t_stack **stack, int mid)
// {
//     t_stack *first;

//     first = *stack;
//     while (*stack != NULL)
//     {
//         if (((*stack)->value) >= mid)
//             (*stack)->pos_mid = 1;
//         if (((*stack)->value) < mid)
//             (*stack)->pos_mid = 0;
//         *stack = (*stack)->next;
//     }
//     *stack = first;
// }
// int     chunk_are_good(t_stack *stack)
// {
//     t_stack *first;

//     first = stack;
//     while (stack != NULL)
//     {
//         if (stack->index_chunk > 3 || stack->index_chunk == -1)
//             return (0);
//         stack= stack->next;
//     }
//     stack = first;
//     return (1);
// }
// void change_chunk(t_stack **stack, t_stack *first, int chunk)
// {
//     *stack = first;
//     int nb;

//     nb = 0;
//     while (*stack != NULL)
//     {
//         if ((*stack)->chunk == chunk)
//         {
//             (*stack)->index_chunk = nb;
//             nb ++;
//         }
//         *stack = (*stack)->next;
//     }
//     *stack = first;
// }

int		len_chunk(t_stack **stack, int chunk)
{
    int len;
    t_stack *first;

    first = *stack;
    len = 0;
    while (*stack != NULL)
    {
        if ((*stack)->chunk == chunk)
            len++;
        *stack = (*stack)->next;
    }
    *stack = first;
    return (len);
}

void	print_tab(int stack[], int len)
{
    int i;

    i = 0;
    while (i < len)
    {
        ft_printf("[%d]", stack[i]);
        i++;
    }
}
