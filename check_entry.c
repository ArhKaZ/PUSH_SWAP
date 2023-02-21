/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:42:51 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/16 14:15:28 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	all_is_digit(char **argv)
{
	int	i;
	int	len;
	int	j;

	j = 0;
	i = 0;
	while (argv[i] != NULL)
	{
		len = ft_strlen(argv[i]);
		j = 0;
		if ((argv[i][0] == '-' || argv[i][0] == '+') && !argv[i][1])
			return (false);
		if (argv[i][0] == '-' || argv[i][0] == '+')
			j++;
		while (j < len)
		{
			if (argv[i][j] == ' ')
				j++;
			if (ft_isdigit(argv[i][j]) != 1)
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

t_bool	compare_nb(char *argv)
{
	int		arg;
	char	*arg_c;

	arg_c = NULL;
	arg = ft_atoi(argv);
	arg_c = ft_itoa(arg);
	if (ft_strncmp(arg_c, argv, 10) == 0)
	{
		free(arg_c);
		return (true);
	}
	free(arg_c);
	return (false);
}

void	nb_in_double(int stack[], int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (stack[i] == stack[j])
			{
				free(stack);
				return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
			}
			j++;
		}
		i++;
	}
}

t_bool	all_is_int(char **argv)
{
	int	i;
	int	len;

	i = 0;
	while (argv[i] != NULL)
	{
		len = ft_strlen(argv[i]);
		if (len > 11 || (len == 11 && argv[i][0] != '-'))
			return (false);
		else
		{
			if (len >= 10)
			{
				if (compare_nb(argv[i]) == false)
					return (false);
			}
		}
		i++;
	}
	return (true);
}

t_bool	checking(char **argv)
{
	if (all_is_digit(argv) == false)
		return (false);
	if (all_is_int(argv) == false)
		return (false);
	return (true);
}
