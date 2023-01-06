/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:13:10 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/06 15:09:34 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_action_p(t_action *actions)
{
	t_action *first;

	first = actions;
	while (actions != NULL)
	{
		ft_printf("[%c]", actions->content);
		actions = actions->next;
	}
	actions = first;
}


void	change_action(t_action **actions, char change, int count)
{
	t_action *before;

	before = (*actions)->before;
	count--;
	del_one_action(*actions);
	*actions = before;
	while (count > 0)
	{
		*actions = (*actions)->before;
		count--;
	}
	(void)change;
	(*actions)->content = change;
}

t_action	*compile_rotate(t_action *actions, char content)
{
	int count;

	count = 0;
	while (actions->content == content)
	{
		actions = actions->next;
		count++;
	}
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

t_bool	diff_than_rotate(char content)
{
	if (content == 'f' || content == 'g' || content == 'i' || content == 'j')
		return (false);
	else
		return (true);
}

void	compile_all_rotate(t_action *actions)
{
	t_action *first;

	first = actions;
	while (actions != NULL)
	{
		if (diff_than_rotate(actions->content) == false)
		{
			actions = compile_rotate(actions, actions->content);
			//actions = first;
		}
		else
			actions = actions->next;
	}
	actions = first;
	//print_action_p(actions);
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

char	*actions_to_char(t_action *actions)
{
	char *all_action;
	char *temp;

	temp = NULL;
	all_action = NULL;
	compile_all_rotate(actions);
	while (actions != NULL)
	{
		//!ft_printf("[%c]", actions->content);
		if (all_action == NULL)
			all_action = char_to_string(actions->content);
		else
		{
			temp = ft_strdup(all_action);
			free(all_action);
			all_action = ft_strjoin(temp, char_to_string(actions->content));
			//!ft_printf("[%s]\n", all_action);
		}
		actions = actions->next;
	}
	free_action(&actions);
	return (all_action);
}