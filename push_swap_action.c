/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_action.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 13:34:52 by syluiset          #+#    #+#             */
/*   Updated: 2022/12/12 13:19:59 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "printf/ft_printf.h"

void	sa(t_stack *stack_a)
{
	int temp;

	ft_printf("sa\n");
	if (!(stack_a->next == NULL || stack_a == NULL))
	{
		temp = stack_a->value;
		stack_a->value = stack_a->next->value;
		stack_a->next->value = temp;
	}
}

void	sb(t_stack *stack_b)
{
	int temp;

	ft_printf("sb\n");
	if (!(stack_b->next == NULL || stack_b == NULL))
	{
		temp = stack_b->value;
		stack_b->value = stack_b->next->value;
		stack_b->next->value = temp;
	}
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("ss\n");
	sa(stack_a);
	sb(stack_b);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first;
	t_stack *temp;

	ft_printf("pa\n");
	first = (*stack_b)->next;
	if (!(*stack_b == NULL))
	{
		temp = create_empty_stack();
		if (!temp)
			return ;
		temp->value = (*stack_b)->value;
		temp->next = NULL;
		stack_add_front(stack_a, temp);
		free((*stack_b));
		(*stack_b) = first;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first;
	t_stack *temp;

	ft_printf("pb\n");
	first = (*stack_a)->next;
	if (!(*stack_a == NULL))
	{
		temp = create_empty_stack();
		if (!temp)
			return ;
		temp->value = (*stack_a)->value;
		temp->next = NULL;
        temp->pos_mid = (*stack_a)->pos_mid;
        temp->chunk = (*stack_a)->chunk;
        temp->index_chunk = (*stack_a)->index_chunk;
		stack_add_front(stack_b, temp);
		free((*stack_a));
		(*stack_a) = first;
	}
}

void	ra(t_stack **stack_a)
{
	t_stack *second;
	t_stack *first;

	ft_printf("ra\n");
	first = (*stack_a);
	second = (*stack_a)->next;
	(*stack_a) = stack_last((*stack_a));
	first->next = NULL;
	(*stack_a)->next = first;
	(*stack_a) = second;
}

void	rb(t_stack **stack_b)
{
	t_stack *second;
	t_stack *first;

	ft_printf("rb\n");
	first = (*stack_b);
	second = (*stack_b)->next;
	(*stack_b) = stack_last((*stack_b));
	first->next = NULL;
	(*stack_b)->next = first;
	(*stack_b) = second;
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rr\n");
	ra(stack_a);
	rb(stack_b);
}

void	rra(t_stack **stack_a)
{
	t_stack *first;
	t_stack *new_last;

	ft_printf("rra\n");
	first = (*stack_a);
	while ((*stack_a)->next->next != NULL)
		(*stack_a) = (*stack_a)->next;
	new_last = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	(*stack_a)->next = first;
	new_last->next = NULL;
}

void	rrb(t_stack **stack_b)
{
	t_stack *first;
	t_stack *new_last;

	ft_printf("rrb\n");
	first = (*stack_b);
	while ((*stack_b)->next->next != NULL)
		(*stack_b) = (*stack_b)->next;
	new_last = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	(*stack_b)->next = first;
	new_last->next = NULL;
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rrr\n");
	rra(stack_a);
	rrb(stack_b);
}