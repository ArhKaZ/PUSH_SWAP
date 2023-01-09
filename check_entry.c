/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:42:51 by syluiset          #+#    #+#             */
/*   Updated: 2023/01/09 18:00:06 by syluiset         ###   ########.fr       */
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
		ft_printf("%s", argv[i]);
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
int		*get_nb(char *argv, int len)
{
	int i;
	int	*tab;
	int j;

	i = 0;
	tab = malloc(sizeof(int) * len);
	i = 0;
	j = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
			j++;
		tab[j] = tab[j] * 10 + argv[i] - '0';
		i++;
	}
	return (tab);
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

t_bool	check_multiple_nb(char *argv)
{
	int *tab;
	int len;

	len = nb_space(argv);
	tab = get_nb(argv, len);
	print_tab(tab, len);
	while (len >= 0)
	{
		if (compare_nb(ft_itoa(tab[len - 1])) == false)
			return (false);
		len--;
	}
	return (true);
}

t_bool	all_is_int(int argc, char **argv)
{
	int i;
	int len;

	i = 1;
	while (i < argc)
	{
		if (is_space(argv[i]) == true)
		{
			return (check_multiple_nb(argv[i]));
		}
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

void	checking(int argc, char **argv)
{
	if (all_is_digit(argc, argv) == false)
	{
		ft_printf("1");
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
	}
	if (all_is_int(argc, argv) == false)
	{
		ft_printf("2");
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
	}
	if (nb_in_double(argc, argv) == false)
	{
		ft_printf("3");
		return (ft_putstr_fd("Error\n", 2), exit(EXIT_FAILURE));
	}
}