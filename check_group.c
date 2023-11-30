/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:31:22 by ezhou             #+#    #+#             */
/*   Updated: 2023/11/30 17:54:20 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_get_size(char ***numbers)
{
	int	size;
	int	i;
	int	j;

	j = 0;
	i = 0;
	size = 0;
	while (numbers[i])
	{
		j = 0;
		while (numbers[i][j])
		{
			size++;
			j++;
		}
		i++;
	}
	return (size);
}

int	is_valid(char c, int j)
{
	if (j == 0)
		return ((c == '+' | c == '-' | ft_isdigit(c)));
	else
		return (ft_isdigit(c));
}

char	***group_args(int argc, char **argv)
{
	char	***result;
	int		i;
	int		j;

	j = 0;
	i = 1;
	result = (char ***)malloc(sizeof(char **) * argc);
	if (!result)
		return (0);
	while (argv[i])
	{
		result[j] = ft_split(argv[i], ' ');
		if (!(result[j]))
		{
			ft_free_tpointer(result);
			return (0);
		}
		i++;
		j++;
	}
	return (result);
}

int	check_numbers(char ***to_check)
{
	int	i;
	int	j;
	int	bool;
	int	k;

	i = 0;
	bool = 1;
	while (to_check[i] && bool)
	{
		j = 0;
		while (to_check[i][j] && bool)
		{
			k = 0;
			while (to_check[i][j][k] && bool)
			{
				bool = is_valid(to_check[i][j][k], k);
				k++;
			}
			j++;
		}
		i++;
	}
	return (bool);
}

int	**generate(char ***numbers)
{
	int	result;
	int	size;
	int	i;
	int	j;

	j = 0;
	i = 0;
	size = ft_get_size(numbers);
	result = (int **)malloc(sizeof(int *) * size);
	if (!result)
		return (0);
	
}

int	main(int argc, char **argv)
{
	char ***aux = group_args(argc, argv);
	printf("%d\n", ft_get_size(aux));
	return (0);
}