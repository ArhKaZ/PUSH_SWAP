/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:13:10 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/20 12:17:08 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	change_action(t_action **actions, char change, int count)
{
	t_action	*before;

	before = (*actions)->before;
	count--;
	del_one_action(*actions);
	*actions = before;
	while (count > 0)
	{
		*actions = (*actions)->before;
		count--;
	}
	(*actions)->content = change;
}

t_action	*compile_rotate(t_action *actions, char content)
{
	int	count;

	count = 0;
	while (actions->next != NULL && actions->content == content)
	{
		actions = actions->next;
		count++;
	}
	if (actions == NULL)
		return (actions);
	if (content == 'f' && actions->content == 'g')
		change_action(&actions, 'h', count);
	if (content == 'g' && actions->content == 'f')
		change_action(&actions, 'h', count);
	if (content == 'i' && actions->content == 'j')
		change_action(&actions, 'k', count);
	if (content == 'j' && actions->content == 'i')
		change_action(&actions, 'k', count);
	return (actions);
}

t_bool	diff_rotate(char content)
{
	if (content == 'f' || content == 'g' || content == 'i' || content == 'j')
		return (false);
	else
		return (true);
}

void	compile_all_rotate(t_action *actions)
{
	t_action	*first;

	first = actions;
	while (actions != NULL)
	{
		if (actions->next != NULL && actions->before != NULL \
			&& diff_rotate(actions->content) == false)
			actions = compile_rotate(actions, actions->content);
		else
			actions = actions->next;
	}
	actions = first;
}

char	*char_to_string(char content)
{
	if (content == 'a')
		return (ft_strdup("sa\n"));
	if (content == 'b')
		return (ft_strdup("sb\n"));
	if (content == 'c')
		return (ft_strdup("ss\n"));
	if (content == 'd')
		return (ft_strdup("pa\n"));
	if (content == 'e')
		return (ft_strdup("pb\n"));
	if (content == 'f')
		return (ft_strdup("ra\n"));
	if (content == 'g')
		return (ft_strdup("rb\n"));
	if (content == 'h')
		return (ft_strdup("rr\n"));
	if (content == 'i')
		return (ft_strdup("rra\n"));
	if (content == 'j')
		return (ft_strdup("rrb\n"));
	if (content == 'k')
		return (ft_strdup("rrr\n"));
	return (NULL);
}
