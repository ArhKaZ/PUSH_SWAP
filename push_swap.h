/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:18:31 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/03 19:08:18 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H
# include <stdlib.h>
# include "Libft_w_a/libft.h"

typedef enum e_bool
{
    false,
    true
}              t_bool;

typedef struct s_stack
{
	int			value;
	int			chunk;
	int			l_chunk;
	struct s_stack	*before;
	struct s_stack	*next;
}					t_stack;

void	go_on_top(t_stack **stack);

t_stack	*create_empty_stack(void);

t_stack	*stack_last(t_stack *stack);

int		len_stack(t_stack **stack);

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

void    choose_sort_tec(t_stack **stack);

void    sort_four(t_stack **stack_a, t_stack **stack_b);

void    sort_five(t_stack **stack_a, t_stack **stack_b);

void    sort_middle_stack(t_stack **stack_a, t_stack **stack_b, int len, int sort_tab[]);

void	print_stack(t_stack *stack);

void	put_pivot(t_stack **stack, int mid);

void	split_at_mid(t_stack **stack_a, t_stack **stack_b, int pos);

int     chunk_are_good(t_stack *stack);

void    give_chunk(t_stack **stack_a, int len, int sort_tab[]);

void	split_in_chunk(t_stack **stack, int pos);

int		len_chunk(t_stack **stack, int chunk);

int		len_stack(t_stack **stack);

int	    *sort_tab_int(int stack[], int len);

void    sort_chunk(t_stack **stack);

void	print_chunk_and_index(t_stack *stack);

void    push_little(t_stack **stack_a, t_stack **stack_b);

#endif