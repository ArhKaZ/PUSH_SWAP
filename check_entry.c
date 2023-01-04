/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:42:51 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/04 16:06:35 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
t_bool	all_is_digit(int argc, char **argv)
{
	int i;
	int j;
	int len;

	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		j = 0;
		while (j < len)
		{
			if (ft_isdigit(argv[i][j]) != 1)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_bool	all_is_int(int argc, char **argv)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (len > 11 || (len == 11 && argv[i][0] != '-'))
			return (false);
		if (len == 11)
		{
			if (ft_strncmp(argv[i], "-2147483648", len) > 0)
				return (false);
		}
		else
		{
			if (ft_strncmp(argv[i], "2147483647", len) > 0)
				return (false);
		}
		i++;
	}
	return (true);
}

t_bool	nb_in_double(int argc, char **argv)
{
	int i;
	int j;
	int len;

	i = 0;
	while (i < argc)
	{
		j = i + 1;
		len = ft_strlen(argv[i]);
		while (j < argc)
		{
			if (ft_strlen(argv[j]) > len)
				len = ft_strlen(argv[j]);
			if (ft_strncmp(argv[i], argv[j], len) == 0)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	checking(int argc, char **argv)
{
	if (all_is_digit(argc, argv) == false)
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
	if (all_is_int(argc, argv) == false)
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
	if (nb_in_double(argc, argv) == false)
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
}