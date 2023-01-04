/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:54:10 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/04 17:17:12 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	len = 0;
	while ((*stack)->before != NULL)
		*stack = (*stack)->before;
	first = *stack;
	while (*stack != NULL)
	{
		len++;
		*stack = (*stack)->next;
	}
	*stack = first;
	return (len);
}

t_bool  compare_to_sort_tab(t_stack **stack_a, int sort_tab[], int len)
{
    int i;
    t_stack *first;

    first = *stack_a;
    i = 0;
    while (i < len)
    {
        if (sort_tab[i] != (*stack_a)->value) {
            *stack_a = first;
            return (false);
        }
        i++;
        *stack_a = (*stack_a)->next;
    }
    *stack_a = first;
    return (true);
}
void    sort_little_stack(t_list_stack *stacks, int len, t_list *actions)
{
    if (len == 2)
        sa(stacks->stack_a, actions);
    if (len == 3) {
        return (choose_sort_tec(&stacks->stack_a, actions));
    }
    if (len == 4)
        return (sort_four(&stacks->stack_a, &stacks->stack_b, actions));
    if (len <= 5) {
        sort_five(&stacks->stack_a, &stacks->stack_b, actions);
    }
}

void	push_swap(int stack[], int len, t_list_stack *stacks, t_list *actions)
{
	t_stack *stack_a;
	t_stack *stack_b;
    stack_a = NULL;
	stack_b = NULL;

	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	fill_stack(stack, len, &stacks->stack_a);
    sort_tab_int(stack, len);
    if (!(compare_to_sort_tab(&stacks->stack_a, stack, len)))
    {
        if (len <= 5)
            sort_little_stack(stacks, len, actions);
        if (len <= 100)
            sort_middle_stack(stacks, len, stack, actions);
    }
	//faire free_stack
}

int main(int argc, char **argv)
{
	int	*stack;
	int i;
	t_list_stack *stacks;
	t_list	*actions;
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
		stacks = malloc(sizeof(t_list_stack));
		if (!stacks)
			return (0);
		actions = malloc(sizeof(t_list));
		if (!actions)
			return (0);
		push_swap(stack, i, stacks, actions);
		free(stacks);
	}
	return (0);
}