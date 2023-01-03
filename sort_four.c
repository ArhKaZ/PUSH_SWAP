/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:09:53 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/03 12:09:54 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_four(t_stack **stack_a, t_stack **stack_b)
{
    push_little(stack_a, stack_b);
    choose_sort_tec(stack_a);
    pa(stack_a, stack_b);
}