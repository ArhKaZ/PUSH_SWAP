/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:54:10 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/06 19:47:36 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_list_stack *stacks, t_action *actions)
{
	int	i;
	int	len_s;
	int	j;

	i = 0;
	len_s = len_stack(&stacks->stack_a);
	while (compare_to_sort_tab(stacks) == false)
	{
		j = 0;
		while (j < len_s)
		{
			if ((stacks->stack_a->index >> i) & 1)
			{
				ra(&stacks->stack_a, actions);
			}
			else
				pb(stacks, actions);
			j++;
		}
		while (stacks->stack_b != NULL)
			pa(stacks, actions);
		i++;
	}
}

void	sort_other_stack(t_list_stack *sts, int len, int tab[], t_action *act)
{
	give_chunks(&sts->stack_a, len, tab);
	sts->chunk_max = chunk_max(sts);
	re_index(&sts->stack_a, tab, len);
	if (len >= 500)
	{
		radix_sort(sts, act);
	}
	else
		push_to_b(sts, act);
}

void	sort_little_stack(t_list_stack *stacks, int len, t_action *actions)
{
	if (len == 2)
		sa(stacks->stack_a, actions);
	else if (len == 3)
		return (choose_sort_tec(&stacks->stack_a, actions));
	else if (len == 4)
		return (sort_four(stacks, actions));
	else if (len == 5)
	{
		sort_five(stacks, actions);
	}
}

void	push_swap(int stack[], int len, t_list_stack *stacks)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_action	*actions;
	char		*actions_c;

	stack_a = NULL;
	stack_b = NULL;
	stacks->stack_a = stack_a;
	stacks->stack_b = stack_b;
	fill_stack(stack, len, &stacks->stack_a);
	sort_tab_int(stack, len);
	if (!(compare_to_sort_tab(stacks)))
	{
		actions = create_empty_list();
		if (!actions)
			return ;
		if (len <= 5)
			sort_little_stack(stacks, len, actions);
		else
			sort_other_stack(stacks, len, stack, actions);
		actions_c = actions_to_char(actions);
		ft_printf("%s", actions_c);
		free(actions_c);
	}
	free(stack);
}

int	main(int argc, char **argv)
{
	int				len;
	int				*stack;
	t_list_stack	*stacks;

	len = 0;
	if (argc > 1)
	{
		stacks = NULL;
		stack = get_arg(argc, argv, &len);
		if (len == 0)
		{
			free(stack);
			return (0);
		}
		nb_in_double(stack, len);
		stacks = malloc(sizeof(t_list_stack));
		if (!stacks)
			return (0);
		push_swap(stack, len, stacks);
		free_stacks(stacks);
	}
	return (0);
}
