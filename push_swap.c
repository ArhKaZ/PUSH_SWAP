/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:54:10 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/10 14:56:35 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_middle_stack(t_list_stack *stacks, int len, int sort_tab[], t_action *actions)
{
    if (len > 100)
        give_chunk_big(&stacks->stack_a, len, sort_tab);
    else
        give_chunk(&stacks->stack_a, len, sort_tab);
    re_index(&stacks->stack_a, sort_tab, len);
    push_to_b(stacks, actions);
    choose_sort_tec(&stacks->stack_a, actions);
    push_back(&stacks->stack_a, &stacks->stack_b, actions);
}

void    sort_little_stack(t_list_stack *stacks, int len, t_action *actions)
{
    if (len == 2)
        sa(stacks->stack_a, actions);
    else if (len == 3)
        return (choose_sort_tec(&stacks->stack_a, actions));
    else if (len == 4)
        return (sort_four(&stacks->stack_a, &stacks->stack_b, actions));
    else if (len == 5) {
        sort_five(&stacks->stack_a, &stacks->stack_b, actions);
    }
}

void	push_swap(int stack[], int len, t_list_stack *stacks)
{
	t_stack *stack_a;
	t_stack *stack_b;
	t_action	*actions;
    stack_a = NULL;
	stack_b = NULL;

	actions = create_empty_list();
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	fill_stack(stack, len, &stacks->stack_a);
    sort_tab_int(stack, len);
    if (!(compare_to_sort_tab(&stacks->stack_a, stack, len)))
    {
        if (len <= 5)
            sort_little_stack(stacks, len, actions);
    	else
            sort_middle_stack(stacks, len, stack, actions);
    };
	ft_printf("%s", actions_to_char(actions));
}


int main(int argc, char **argv)
{
	int len;
	int *stack;
	t_list_stack *stacks;

	len = 0;
	if (argc > 1)
	{
		checking(argc, argv);
		stack = get_arg(argc, argv, &len);
		stacks = malloc(sizeof(t_list_stack));
		if (!stacks)
			return (0);
		push_swap(stack, len, stacks);
		free_stacks(stacks);
	}
	return (0);
}