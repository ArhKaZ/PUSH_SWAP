/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:58:42 by syluiset          #+#    #+#             */
/*   Updated: 2022/12/14 13:13:55 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <stdlib.h>

typedef struct s_stack
{
	int			value;
	int			pos_mid;
	int			chunk;
	int			index_chunk;
	struct s_stack	*next;
}					t_stack;

t_stack	*create_empty_stack(void);

t_stack	*stack_last(t_stack *stack);

void	stack_add_back(t_stack **stack_a, t_stack *new);

void	stack_add_front(t_stack **stack_to, t_stack *new);

void	fill_stack(int stack[], int len, t_stack **stack_a);

void	sa(t_stack *stack_a);

void	sb(t_stack *stack_b);

void	ss(t_stack *stack_a, t_stack *stack_b);

void	pa(t_stack **stack_a, t_stack **stack_b);

void	pb(t_stack **stack_a, t_stack **stack_b);

void	ra(t_stack **stack_a);

void	rb(t_stack **stack_b);

void	rr(t_stack **stack_a, t_stack **stack_b);

void	rra(t_stack **stack_a);

void	rrb(t_stack **stack_b);

void	rrr(t_stack **stack_a, t_stack **stack_b);

void	print_stack(t_stack *stack);
#endif