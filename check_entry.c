/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:42:51 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/10 14:36:48 by syluiset         ###   ########.fr       */
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
		if (argv[i][0] == '-')
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
	int arg;
	char *arg_c;

	arg_c = malloc(sizeof(char) * 11);
	arg = ft_atoi(argv);
	arg_c = ft_itoa(arg);
	if (ft_strncmp(arg_c, argv, 10) == 0)
		return (true);
	else
		return (false);
}

t_bool	is_space(char *argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			return (true);
		i++;
	}
	return (false);
}
t_bool check_nb(long int nb, t_bool neg)
{
	if (neg == true && nb < -2147483648)
		return (false);
	else
	{
		if (nb > 2147483647)
			return (false);
		else
			return (true);
	}
}
t_bool	check_multiple_nb(char *argv)
{
	t_bool neg;
	long int nb;
	int i;

	i = 0;
	nb = 0;
	neg = false;
	while (*argv)
	{
		if (i == 10)
			return (check_nb(nb, neg));
		if (*argv == '-')
			neg = true;
		if (*argv == ' ')
		{
			i = 0;
			argv++;
		}
		else
		{
			nb = nb * 10 + *argv - 48;
			argv++;
			i++;
		}
	}
	return (true);
}


t_bool	nb_in_double(int argc, char **argv)
{
	int i;
	int j;
	size_t len;

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

t_bool	all_is_int(int argc, char **argv)
{
	int i;
	int len;

	i = 1;
	if (argc == 2 && is_space(argv[1]) == true)
		check_multiple_nb(argv[i]);
	else
	{
		while (i < argc)
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
	}
	return (true);
}

void	checking(int argc, char **argv)
{
	if (all_is_digit(argc, argv) == false)
	{
		return (ft_putstr_fd("Error1\n", 2), exit(EXIT_FAILURE));
	}
	if (all_is_int(argc, argv) == false)
	{
		return (ft_putstr_fd("Error2\n", 2), exit(EXIT_FAILURE));
	}
	if (nb_in_double(argc, argv) == false)
	{
		return (ft_putstr_fd("Error3\n", 2), exit(EXIT_FAILURE));
	}
}