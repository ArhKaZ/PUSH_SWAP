/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:18:31 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/06 16:02:49 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include "Libft_w_a/libft.h"

typedef enum e_bool
{
	false,
	true
}			t_bool;

typedef struct s_action
{
	char			content;
	struct s_action	*before;
	struct s_action	*next;
}					t_action;

typedef struct s_stack
{
	int				value;
	int				chunk;
	int				index;
	struct s_stack	*before;
	struct s_stack	*next;
}					t_stack;

typedef struct s_list_stack
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		chunk_max;
}				t_list_stack;

typedef struct s_help
{
	int		chunk;
	int		i;
	int		act_len;
	int		len;
	t_stack	*first;
}				t_help;

# define SA 'a'
# define SB 'b'
# define SS 'c'
# define PA 'd'
# define PB 'e'
# define RA 'f'
# define RB 'g'
# define RR 'h'
# define RRA 'i'
# define RRB 'j'
# define RRR 'k'

void		compile_all_rotate(t_action *actions);

char		*char_to_string(char content);

int			place_little_at_top_down(t_stack **stack_a, int value);

int			place_little_at_top_up(t_stack **stack_a, int value);

int			place_little_at_bottom_down(t_stack **stack_b, int little);

int			place_little_at_bottom_up(t_stack **stack_b, int little);

void		nb_in_double(int stack[], int len);

void		radix_sort(t_list_stack *sts, t_action *acts);

void		index_to_bin(t_stack **stack_a);

int			get_min_chunk(t_stack **stack_a, int chunk);

int			get_max_chunk(t_stack **stack_a, int chunk);

void		place_on_chunk(t_list_stack *sts, t_action *acts, int chunk);

void		give_chunks(t_stack **stack_a, int len, int sort_tab[]);

void		re_index(t_stack **stack_a, int sort_tab[], int len);

void		push_back(t_list_stack *sts, t_action *acts, int chunk);

void		push_to_b(t_list_stack *sts, t_action *acts);

t_bool		compare_to_sort_tab(t_list_stack *sts);

void		place_in_the_middle(t_list_stack *sts, t_action *acts);

t_stack		*next_push_to_b(t_stack **stack_a, int chunk, t_action *acts);

int			chunk_max(t_list_stack *sts);

t_stack		*create_empty_stack(void);

t_stack		*stack_last(t_stack *stack);

int			len_stack(t_stack **stack);

void		stack_add_back(t_stack **stack_a, t_stack *new);

void		stack_add_front(t_stack **stack_to, t_stack *new);

void		fill_stack(int stack[], int len, t_stack **stack_a);

void		sa(t_stack *stack_a, t_action *acts);

void		sb(t_stack *stack_b, t_action *acts);

void		ss(t_list_stack *sts, t_action *acts);

void		pa(t_list_stack *sts, t_action *acts);

void		pb(t_list_stack *sts, t_action *acts);

void		ra(t_stack **stack_a, t_action *acts);

void		rb(t_stack **stack_b, t_action *acts);

void		rr(t_list_stack *sts, t_action *acts);

void		rra(t_stack **stack_a, t_action *acts);

void		rrb(t_stack **stack_b, t_action *acts);

void		rrr(t_list_stack *sts, t_action *acts);

void		choose_sort_tec(t_stack **stack, t_action *acts);

void		sort_four(t_list_stack *sts, t_action *acts);

void		sort_five(t_list_stack *sts, t_action *acts);

void		sort_mid(t_list_stack *sts, int len, int tab[], t_action *acts);

t_action	*create_empty_list(void);

int			len_chunk(t_stack **stack, int chunk);

int			len_stack(t_stack **stack);

int			*sort_tab_int(int stack[], int len);

void		sort_chunk(t_stack **stack);

void		push_little(t_list_stack *sts, t_action *acts, int little);

int			find_little(t_stack **stack_a);

void		add_action_list(t_action **acts, char content);

void		free_stacks(t_list_stack *sts);

t_action	*del_one_action(t_action *acts);

char		*actions_to_char(t_action *acts);

void		free_action(t_action **acts, t_action *first);

void		get_little_on_top(t_stack **stack_a, t_action *acts, int chunk);

void		get_little_on_bottom(t_stack **stack_b, t_action *acts, int chunk);

int			place_little_up(t_stack **stack_a, int value);

int			place_little_down(t_stack **stack_a, int value);

void		actiondelone(t_action *action);

t_bool		checking(char **argv);

int			*get_arg(int argc, char **argv, int *len);

t_bool		check_multiple_nb(char *argv);

t_bool		compare_nb(char *argv);
#endif