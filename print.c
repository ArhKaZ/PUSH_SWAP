/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 18:33:41 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/06 14:44:34 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
void	print_stack(t_stack *stack)
{
	t_stack *first;

	first = stack;
	ft_printf("[");
		while (stack != NULL)
		{
			ft_printf("%d ", stack->value);
			stack = stack->next;
		}
		ft_printf("]\n");
		stack = first;
}

void	print_chunk_and_index(t_stack *stack)
{
	t_stack *first;

	first = stack;
		while (stack != NULL)
		{
			ft_printf("[%d/%d/%d/%p/%p] ", stack->value, stack->chunk, stack->index, stack->before, stack->next);
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
        ft_printf("[%d/%d]", stack[i], i);
        i++;
    }
}
