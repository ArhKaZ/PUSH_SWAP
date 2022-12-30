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

void    push_to_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *first;
    int chunk;

    chunk = 0;
    first = *stack_a;
    while (len_stack(stack_a) > 3)
    {
        //print_chunk_and_index(*stack_a);
        if ((*stack_a)->chunk == chunk)
            pb(stack_a, stack_b);
        else
        {
            if (len_chunk(stack_a, chunk) == 0)
                chunk++;
            else
                //ra(stack_a);
                stack_a = next_push_to_b(stack_a, chunk);
        }
    }
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

void	print_chunk_and_index_of_chunk(t_stack *stack, int chunk)
{
	t_stack *first;

	first = stack;
		while (stack != NULL && stack->chunk == chunk)
		{
			ft_printf("[%d/%d/%d/%d] ", stack->value, stack->chunk, stack->l_chunk);
			stack = stack->next;
		}
		ft_printf("\n");
		stack = first;
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
    len_chunk = len / 5;
    while (*stack_a != NULL)
    {
        if ((*stack_a)->chunk == -1 && (*stack_a)->value <= sort_tab[len_chunk - 1])
        {
            (*stack_a)->chunk = chunk;
            i++;
        }
        if (i == len / 5 && len_chunk + len / 5 <= len) {
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

// void    give_index(t_stack **stack_a, int len, int sort_tab[])
// {
//     int i;
//     int j;
//     int chunk;
//     t_stack *first;

//     chunk = 0;
//     j = 0;
//     first = *stack_a;
//     while (chunk < 5)
//     {
//         i = 0;
//         while (i < len / 5)
//         {
//             if (*stack_a == NULL)
//                 *stack_a = first;
//             if ((*stack_a)->value == sort_tab[j])
//             {
//                 (*stack_a)->index_chunk = i;
//                 *stack_a = first;
//                 j++;
//                 i++;
//             }
//             *stack_a = (*stack_a)->next;
//         }
//         *stack_a = first;
//         chunk++;
//     }
// }

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

    first = *stack_a;
    max = (*stack_a)->value;
    while ((*stack_a) != NULL)
    {
        if ((*stack_a)->chunk == chunk && (*stack_a)->value > max)
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
    while (*stack_a != NULL)
    {
        while ((*stack_a)->chunk != chunk)
        *stack_a = (*stack_a)->next;
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
    ft_printf("[%d/", value);
    while (*stack_a != NULL)
    {
        while ((*stack_a)->chunk != chunk)
            *stack_a = (*stack_a)->before;
        if (value > (*stack_a)->value && value < (*stack_a)->next->value)
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
        {
            down++;
            break;
        }
        down++;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (down);
}

int     place_little_up(t_stack **stack_a, int value)
{
    int up;
    t_stack *first;

    //!ft_printf("place little :");
    //!print_chunk_and_index(*stack_a);
    //!ft_printf("%d", value);
    first = *stack_a;
    up = 0;
    *stack_a = stack_last(*stack_a);
    //!ft_printf("value : [%d/%d/%d]\n",value, (*stack_a)->value ,value == (*stack_a)->value);
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

    //!print_chunk_and_index(*stack_a);
    little = get_min(stack_a);
    down = place_little_up(stack_a, little);
    up = place_little_down(stack_a, little);
    if (up < down)
    {
        while (up >= 0)
            {
                ra(stack_a);
                up--;
            }
    }
    else
    {
        while (down >= 0)
        {
            rra(stack_a);
            down--;
        }
    }
}

void    place_in_the_middle(t_stack **stack_a, t_stack **stack_b)
{
    int up;
    int down;

    up = place_middle_up(stack_a, (*stack_b)->value, (*stack_b)->chunk);
    down = place_middle_down(stack_a, (*stack_b)->value,  (*stack_b)->chunk);
    ft_printf("%d/%d", down, up);
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
    get_little_on_top(stack_a);
}

void    push_back(t_stack **stack_a, t_stack **stack_b)
{
    int chunk;

    chunk = 4;
    while (*stack_b != NULL)
    {
        ft_printf("\n%d\n", (*stack_b)->value);
        print_chunk_and_index(*stack_a);
        if (len_chunk(stack_b, chunk) == 0)
        {
            pa(stack_a, stack_b);
            print_chunk_and_index(*stack_a);
            chunk--;
        }
        if ((*stack_b)->value > get_max_chunk(stack_a, chunk))
        {
            pa(stack_a, stack_b);
            rra(stack_a);
            print_chunk_and_index(*stack_a);
        }
        else if ((*stack_b)->value < get_min_chunk(stack_a, chunk))
        {
            pa(stack_a, stack_b);
            print_chunk_and_index(*stack_a);
        }
        else
        {
            place_in_the_middle(stack_a, stack_b);
            print_chunk_and_index(*stack_a);
        }
    }
}

void    sort_middle_stack(t_stack **stack_a, t_stack **stack_b, int len, int sort_tab[])
{
    int i;

    i = 0;
    give_chunk(stack_a, len, sort_tab);
    //give_index(stack_a, len, sort_tab);
    push_to_b(stack_a, stack_b);
   // print_chunk_and_index(*stack_a);
   // print_chunk_and_index(*stack_b);
    choose_sort_tec(stack_a);
    push_back(stack_a, stack_b);
}