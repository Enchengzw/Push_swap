/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:31:22 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 14:07:08 by ezhou            ###   ########.fr       */
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

int	ft_is_valid(char c, int j)
{
	if (j == 0)
		return ((c == '+' | c == '-' | ft_isdigit(c)));
	else
		return (ft_isdigit(c));
}

char	***ft_group_args(int argc, char **argv)
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
	result[j] = 0;
	return (result);
}

int	ft_check_numbers(char ***to_check)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (to_check[i])
	{
		j = 0;
		while (to_check[i][j])
		{
			k = 0;
			while (to_check[i][j][k])
			{
				if (!ft_is_valid(to_check[i][j][k], k))
				{
					ft_printf("There are non digits arguments\n");
					return (0);
				}
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}
