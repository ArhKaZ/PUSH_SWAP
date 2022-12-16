/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:54:10 by syluiset          #+#    #+#             */
/*   Updated: 2022/12/14 14:59:32 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
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

void	put_pivot(t_stack **stack, int mid)
{
	t_stack *first;

	first = *stack;
	ft_printf("mid = %d\n", mid);
	while (*stack != NULL)
	{
		if (((*stack)->value) >= mid)
		{
			ft_printf("1 %d ", (*stack)->value);
			(*stack)->pos_mid = 1;
		}
		if (((*stack)->value) < mid)
		{
			ft_printf("0 %d ", (*stack)->value);
			(*stack)->pos_mid = 0;
		}
		*stack = (*stack)->next;
	}
	*stack = first;
}

int		stack_is_split(t_stack **stack)
{
	t_stack *first;

	first = *stack;
	while (*stack != NULL)
	{
		if ((*stack)->pos_mid == 0)
		{
			*stack = first;
			return 0;
		}
		*stack = (*stack)->next;
	}
	*stack = first;
	return (1);
}
void	split_at_mid(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *first;
	int test;

	test = 0;
	first = *stack_a;
	while (test == 0)
	{
		if ((*stack_a)->pos_mid == 0)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		test = stack_is_split(stack_a);
	}
	print_stack(*stack_b);
	print_stack(*stack_a);
}
void	sort_desc(t_stack **stack)
{
	
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int mid)
{
	put_pivot(stack_a, mid);
	split_at_mid(stack_a, stack_b);
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
	sort_stack(&stack_a, &stack_b, mid);
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