/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:18:31 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/05 18:54:30 by syluiset         ###   ########.fr       */
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

typedef struct s_action
{
	char	*content;
	struct s_action *before;
	struct s_action *next;
}					t_action;

typedef struct s_stack
{
	int			value;
	int			chunk;
	int			index;
	struct s_stack	*before;
	struct s_stack	*next;
}					t_stack;

typedef	struct s_list_stack
{
	t_stack	*stack_a;
	t_stack *stack_b;
}				t_list_stack;

void	print_tab(int stack[], int len);

void	go_on_top(t_stack **stack);

t_stack	*create_empty_stack(void);

t_stack	*stack_last(t_stack *stack);

int		len_stack(t_stack **stack);

void	stack_add_back(t_stack **stack_a, t_stack *new);

void	stack_add_front(t_stack **stack_to, t_stack *new);

void	fill_stack(int stack[], int len, t_stack **stack_a);

void	sa(t_stack *stack_a, t_action *actions);

void	sb(t_stack *stack_b, t_action *actions);

void	ss(t_stack *stack_a, t_stack *stack_b, t_action *actions);

void	pa(t_stack **stack_a, t_stack **stack_b, t_action *actions);

void	pb(t_stack **stack_a, t_stack **stack_b, t_action *actions);

void	ra(t_stack **stack_a, t_action *actions);

void	rb(t_stack **stack_b, t_action *actions);

void	rr(t_stack **stack_a, t_stack **stack_b, t_action *actions);

void	rra(t_stack **stack_a, t_action *actions);

void	rrb(t_stack **stack_b, t_action *actions);

void	rrr(t_stack **stack_a, t_stack **stack_b, t_action *actions);

void    choose_sort_tec(t_stack **stack, t_action *actions);

void    sort_four(t_stack **stack_a, t_stack **stack_b, t_action *actions);

void    sort_five(t_stack **stack_a, t_stack **stack_b, t_action *actions);

void    sort_middle_stack(t_list_stack *stacks, int len, int sort_tab[], t_action *actions);

void	print_stack(t_stack *stack);

void	print_list(t_action *actions);

t_action	*create_empty_list();

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

void    push_little(t_stack **stack_a, t_stack **stack_b, t_action *actions);

void	add_action_list(t_action **actions, char *content);

void	free_stacks(t_list_stack *stacks);

t_action	*del_one_action(t_action *actions);

char	*actions_to_char(t_action *actions);

void	print_action_p(t_action *actions);
#endif