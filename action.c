/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:54:26 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/06 14:48:17 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_action	*create_empty_list()
{
	t_action	*list;

	list = malloc(sizeof(t_action));
	if (!list)
		return (NULL);
	list->content = 'z';
	list->next = NULL;
	list->before = NULL;
	return (list);
}

t_action	*ft_last_action(t_action *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	ft_action_add_back(t_action **list, t_action *new)
{
	t_action	*temp;

	if (!list || !new)
		return ;
	if (*list != NULL)
	{
		temp = ft_last_action(*list);
		new->before = temp;
		temp->next = new;
	}
	else
		*list = new;
}

t_action	*ft_action_new(char content)
{
	t_action	*element;

	element = malloc(sizeof(t_action));
	if (!element)
		return (NULL);
	element->content = content;
	element->next = NULL;
	element->before = NULL;
	return (element);
}

t_action	*del_one_action(t_action *actions)
{
	t_action *before;
	t_action *next;

	before = actions->before;
	next = actions->next;

	free(actions);
	before->next = next;
	next->before = before;
	actions = before;
	return (actions);
}

void	add_action_list(t_action **actions, char content)
{
	t_action *new;

	if ((*actions)->content == 'z')
		(*actions)->content = content;
	else
	{
		new = ft_action_new(content);
		ft_action_add_back(actions, new);
	}
}