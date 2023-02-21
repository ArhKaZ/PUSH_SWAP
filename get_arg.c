/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syluiset <syluiset@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:06:22 by syluiset          #+#    #+#             */
/*   Updated: 2023/02/06 19:32:23 by syluiset         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_custom(const char *nptr, int *i)
{
	int					neg;
	long long int		ret;
	char				*nptr0;

	nptr0 = (char *)nptr;
	ret = 0;
	neg = 1;
	while ((nptr0[*i] >= 9 && nptr0[*i] <= 13) || nptr0[*i] == 32)
		*i += 1;
	if (nptr0[*i] == '+' || nptr0[*i] == '-')
	{
		if (nptr0[*i] == '-')
			neg = -1;
		*i += 1;
	}
	while (nptr0[*i] >= '0' && nptr0[*i] <= '9')
	{
		if (ret != ((ret * 10 + (neg * (nptr0[*i] - 48))) / 10))
			return ((neg + 1) / 2 / -1);
		ret = ret * 10 + ((nptr0[*i] - 48) * neg);
		*i += 1;
	}
	return ((int)ret);
}

int	count_nb(char *s, char c)
{
	int	words;
	int	i;

	i = 0;
	words = 0;
	if (c == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		while (s[i] != c && s[i])
			i++;
		words++;
	}
	return (words);
}

int	*get_empty_tab(char **argv, int argc)
{
	int	*stack;
	int	j;
	int	nb_w;

	nb_w = 0;
	j = 1;
	while (j < argc)
	{
		nb_w += count_nb(argv[j], ' ');
		j++;
	}
	stack = calloc(nb_w, sizeof(int));
	return (stack);
}

int	full_tab(char **temp, int *stack, int len)
{
	int	i;

	i = 0;
	if (!temp[0] || checking(temp) == false)
	{
		free(stack);
		while (temp[i] != NULL)
		{
			free(temp[i]);
			i++;
		}
		free(temp);
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	while (temp[i] != NULL)
	{
		stack[len] = ft_atoi(temp[i]);
		len++;
		i++;
	}
	return (len);
}

int	*get_arg(int argc, char **argv, int *len)
{
	int		*stack;
	int		j;
	char	**temp;
	int		i;

	j = 1;
	stack = get_empty_tab(argv, argc);
	while (j < argc)
	{
		temp = ft_split(argv[j], ' ');
		*len = full_tab(temp, stack, *len);
		i = 0;
		while (temp[i] != NULL)
		{
			free(temp[i]);
			i++;
		}
		free(temp);
		j++;
	}
	return (stack);
}
