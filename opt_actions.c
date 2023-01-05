/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:13:10 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/05 19:01:01 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_action_p(t_action *actions)
{
	t_action *first;

	first = actions;
	while (actions != NULL)
	{
		ft_printf("[%s]", actions->content);
		actions = actions->next;
	}
	actions = first;
}

t_bool	diff_than_rotate(char *content)
{
	int len;

	len = ft_strlen(content) - 1;
	if (len == 2)
	{
		if (ft_strncmp(content, "rr", 2) == 0)
			return (true);
	}
	if (len == 3)
	{
		if (ft_strncmp(content, "rrr", 3) == 0)
			return (true);
	}
	if (ft_strncmp(content, "r", 1) == 0)
		return (false);
	else
		return (true);
}

char	*change_action(int len)
{
	if (len == 4)
		return (ft_strdup("rrr\n"));
	else
		return (ft_strdup("rr\n"));
}

t_action	*compile_rotate(t_action *actions, char *content)
{
	int len;

	len = ft_strlen(content);
	while (ft_strncmp(actions->content, content, len) == 0)
		actions = actions->next;
	if (ft_strncmp(actions->content, content, len) == -1 || \
	ft_strncmp(actions->content, content, len) == 1)
	{
		del_one_action(actions->before);
		free(actions->content);
		actions->content = ft_strdup(change_action(len));
	}
	return (actions);
}

void	compile_all_rotate(t_action *actions)
{
	t_action *first;

	first = actions;
	while (actions != NULL)
	{
		//ft_printf("%s, %d", actions->content ,diff_than_rotate(actions->content));
		if (diff_than_rotate(actions->content) == true)
		{
			//ft_printf("%s", actions->content);
			actions = actions->next;
		}
		else
		{
			actions = compile_rotate(actions, actions->content);
			//if (diff_than_rotate(actions->content) == false)
				//actions = first;
		}
	}
	actions = first;
	print_action_p(actions);
}


char	*actions_to_char(t_action *actions)
{
	char *all_action;
	char *temp;

	all_action = NULL;
	//!print_action_p(actions);
	compile_all_rotate(actions);
	while (actions != NULL)
	{
		if (all_action == NULL)
			all_action = ft_strdup(actions->content);
		else
		{
			temp = ft_strdup(all_action);
			free(all_action);
			all_action = ft_strjoin(temp, actions->content);
		}
		actions = actions->next;
	}
	return (all_action);
}