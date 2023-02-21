/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 20:22:59 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 20:22:59 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	give_last_chunk(t_stack **stack_a, int chunk)
{
	while (*stack_a != NULL)
	{
		if ((*stack_a)->chunk == -1)
			(*stack_a)->chunk = chunk;
		*stack_a = (*stack_a)->next;
	}
}

void	fx(t_help *h, t_stack *stack_a, int len_chunk, int tab[])
{
	while (stack_a != NULL)
	{
		if (stack_a->chunk == -1 && stack_a->value <= tab[h->act_len - 1])
		{
			stack_a->chunk = h->chunk;
			h->i += 1;
		}
		if (h->i == len_chunk && h->act_len + len_chunk <= h->len)
		{
			stack_a = h->first;
			h->act_len += len_chunk;
			h->chunk += 1;
			h->i = 0;
		}
		else
		{
			if (h->act_len + len_chunk > h->len && stack_a->next == NULL)
			{
				stack_a = h->first;
				give_last_chunk(&stack_a, h->chunk + 1);
			}
			else
				stack_a = stack_a->next;
		}
	}
}

void	give_chunk(t_stack **stack_a, int len, int tab[], int len_chunk)
{
	t_help	*h;

	h = malloc(sizeof(t_help));
	h->chunk = 0;
	h->i = 0;
	h->act_len = len_chunk;
	h->len = len;
	h->first = *stack_a;
	fx(h, *stack_a, len_chunk, tab);
	*stack_a = h->first;
	free(h);
}

void	give_chunks(t_stack **stack_a, int len, int tab[])
{
	if (len > 100)
		give_chunk(stack_a, len, tab, len / 10);
	else
		give_chunk(stack_a, len, tab, len / 5);
}
