/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:09:53 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/05 16:50:18 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_four(t_stack **stack_a, t_stack **stack_b, t_action *actions)
{
    push_little(stack_a, stack_b, actions);
    choose_sort_tec(stack_a, actions);
    pa(stack_a, stack_b, actions);
}