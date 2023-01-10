/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:06:22 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/10 14:51:38 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		nb_space(char *argv)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			count++;
		i++;
	}
	return (count);
}

int	*all_in_one_arg(char *argv)
{
	int spaces;
	int *tab;
	int i;

	i = 0;
	spaces = nb_space(argv);
	tab = ft_calloc(spaces + 1, sizeof(int));
	if (!tab)
		return (NULL);
	while (*argv)
	{
		if (*argv == ' ')
		{
			i++;
			argv++;
		}
		else
		{
			tab[i] = tab[i] * 10 + *argv - 48;
			argv++;
		}
	}
	return (tab);
}

int	*all_in_multi_arg(int argc, char **argv)
{
	int *stack;
	int i;

	i = 0;
	stack = malloc(sizeof(int) * argc - 1);
	if (!stack)
		return (0);
	while (i + 1 < argc)
	{
		stack[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	return (stack);
}

int	*get_arg(int argc, char **argv, int *len)
{
	int *stack;

	if (argc == 2)
	{
		*len = nb_space(argv[1]) + 1;
		stack = all_in_one_arg(argv[1]);
	}
	else
	{
		*len = argc - 1;
		stack = all_in_multi_arg(argc, argv);
	}
	return (stack);
}