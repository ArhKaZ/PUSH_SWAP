/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt_actions_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:11:43 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/13 21:11:43 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*trans_to_char(t_action *actions)
{
	char	*all_action;
	char	*temp;
	char	*temp2;

	all_action = NULL;
	while (actions != NULL)
	{
		if (all_action == NULL)
			all_action = char_to_string(actions->content);
		else
		{
			temp = ft_strdup(all_action);
			free(all_action);
			temp2 = char_to_string(actions->content);
			all_action = ft_strjoin(temp, temp2);
			free(temp);
			free(temp2);
		}
		actions = actions->next;
	}
	return (all_action);
}

char	*actions_to_char(t_action *actions)
{
	char		*all_action;
	t_action	*first;

	first = actions;
	compile_all_rotate(actions);
	all_action = trans_to_char(actions);
	free_action(&actions, first);
	return (all_action);
}
