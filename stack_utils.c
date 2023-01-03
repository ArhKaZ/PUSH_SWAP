/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:01:26 by syluiset          #+#    #+#             */
/*   Updated: 2022/12/22 10:32:20 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

t_stack	*create_empty_stack(void)
{
	t_stack *stack_to_return;

	stack_to_return = malloc(sizeof(t_stack));
	if (!stack_to_return)
		return (NULL);
	stack_to_return->value = 0;
	stack_to_return->pos_mid = 0;
	stack_to_return->chunk = -1;
	stack_to_return->index_chunk = -1;
	stack_to_return->next = NULL;
	return (stack_to_return);
}

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}

void	stack_add_back(t_stack **stack_to, t_stack *new)
{
	t_stack	*temp;

	new->next = NULL;
	if (!stack_to || !new)
		return ;
	if (*stack_to != NULL)
	{
		temp = stack_last(*stack_to);
		temp->next = new;
	}
	else
		*stack_to = new;
}

void	stack_add_front(t_stack **stack_to, t_stack *new)
{
	if (!stack_to || !new)
		return ;
	if (*stack_to != NULL)
	{
		new->next = *stack_to;
		*stack_to = new;
	}
	else
	{
		new->next = NULL;
		*stack_to = new;
	}
}
void	fill_stack(int stack[], int len, t_stack **stack_a)
{
	int		i;
	t_stack *new;

	i = 0;
	while (i < len)
	{
		new = create_empty_stack();
		if (!new)
			return ;
		new->value = stack[i];
	//	new->next = NULL;
		stack_add_back(stack_a, new);
		i++;
	}
	free(stack);
}
