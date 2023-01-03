/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:54:10 by syluiset          #+#    #+#             */
/*   Updated: 2022/12/22 10:18:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"
#include "printf/ft_printf.h"


void	print_stack(t_stack *stack)
{
	t_stack *first;

	first = stack;
		while (stack != NULL)
		{
			ft_printf("%d ", stack->value);
			stack = stack->next;
		}
		ft_printf("\n");
		stack = first;
}

void	print_chunk_and_index(t_stack *stack)
{
	t_stack *first;

	first = stack;
		while (stack != NULL)
		{
			ft_printf("[%d/%d/%d/%d] ", stack->value, stack->pos_mid, stack->chunk, stack->index_chunk);
			stack = stack->next;
		}
		ft_printf("\n");
		stack = first;
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

int	*sort_tab_int(int stack[], int len)
{
	int i;
	int j;
	int temp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (stack[j] > stack[i])
			{
				temp = stack[j];
				stack[j] = stack[i];
				stack[i] = temp;
			}
			else
				j++;
		}
		i++;
	}
	return (stack);
}

int		len_stack(t_stack **stack)
{
	int len;
	t_stack *first;

	first = *stack;
	len = 0;
	while (*stack != NULL)
	{
		len++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (len);
}

void    push_on_b(t_stack **stack_a, t_stack **stack_b)
{
    int len;

    len = len_chunk(*stack_a, *stack_a, (*stack_a)->chunk);
    if (len == 1)
        pb(stack_a, stack_b);
    if (len == 2)
    {
        pb(stack_a, stack_b);
        pb(stack_a, stack_b);
    }
    if (len == 3)
    {
        pb(stack_a, stack_b);
        pb(stack_a, stack_b);
        pb(stack_a, stack_b);
    }
}

int		is_sort(t_stack *stack_a, int sort_tab[])
{
	int i;
	t_stack *first;

	first = stack_a;
	i = 0;
	while (stack_a != NULL)
	{
		if (stack_a->value != sort_tab[i])
		{
			stack_a = first;
			return (0);
		}
		stack_a = stack_a->next;
		i++;
	}
	return (1);
}

void    sort_first_cat(t_stack **stack_a, t_stack **stack_b, int sort_tab[])
{
	(void)stack_a;
	(void)stack_b;
	(void)sort_tab;
	// while (is_sort(*stack_a, sort_tab))
	// {
    // 	push_on_b(stack_a, stack_b);

	// }
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int mid, int sort_tab[])
{
    put_pivot(stack_a, mid);
    split_at_mid(stack_a, stack_b);
    while (chunk_are_good(*stack_b) != 1)
        split_in_chunk(stack_b);
    while (chunk_are_good(*stack_a) != 1)
        split_in_chunk(stack_a);
    print_chunk_and_index(*stack_a);
    sort_first_cat(stack_a, stack_b, sort_tab);
    print_chunk_and_index(*stack_b);
}

void	push_swap(int stack[], int len)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int mid;

	stack_a = NULL;
	stack_b = NULL;

	fill_stack(stack, len, &stack_a);
	sort_tab_int(stack, len);
	mid = stack[(len / 2)];
	sort_stack(&stack_a, &stack_b, mid, stack);
}


int main(int argc, char **argv)
{
	int *stack;
	int i;

	i = 0;
	if (argc > 1)
	{
		stack = malloc(sizeof(int) * argc);
		if (!stack)
			return (0);
		while (i + 1 < argc)
		{
			stack[i] = ft_atoi(argv[i + 1]);
			i++;
		}
		push_swap(stack, i);
	}
	return (0);
}