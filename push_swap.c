/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:54:10 by syluiset          #+#    #+#             */
/*   Updated: 2022/12/11 16:16:51 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"
#include "printf/ft_printf.h"

int	find_little_nb(t_stack **stack_a)
{
	int little;
	int place;
	int little_place;

	place = 0;
	little = (*stack_a)->value;
	while ((*stack_a) != NULL)
	{
		(*stack_a) = (*stack_a)->next;
		place++;
		if ((*stack_a)->value < little)
		{
			little = (*stack_a)->value;
			little_place = place;
		}
	}
	return (little_place);
}

// void	sort_little_stack(t_stack *stack_a, t_stack *stack_b)
// {
// 	//int	change_place;
// 	while (stack_a != NULL)
// 	{
// 		change_place = find_little_nb(&stack_a);

// 	}
// }
void	print_stack(t_stack *stack)
{
	t_stack *first;

	first = stack;
		while (stack != NULL)
		{
			ft_printf("%d", stack->value);
			stack = stack->next;
		}
		ft_printf("\n");
		stack = first;
}

void	push_swap(int stack[], int len)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	(void)stack_b;
	fill_stack(stack, len, &stack_a);
	//stack_b = create_empty_stack();
	ft_printf("1/ \n");
	print_stack(stack_a);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	pb(&stack_a, &stack_b);
	ft_printf("2/ \n");
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("3/ \n");
	ss(stack_a, stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("4/ \n");
	rr(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("5/ \n");
	rrr(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	pa(&stack_a, &stack_b);
	print_stack(stack_a);
	print_stack(stack_b);
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