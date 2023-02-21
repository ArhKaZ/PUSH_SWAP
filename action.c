/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 21:01:34 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/16 10:56:46 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_action	*create_empty_list(void)
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

void	add_action_list(t_action **actions, char content)
{
	t_action	*new;

	if ((*actions)->content == 'z')
		(*actions)->content = content;
	else
	{
		new = ft_action_new(content);
		if (!new)
			return ;
		ft_action_add_back(actions, new);
	}
}
