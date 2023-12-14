/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_number_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:43:36 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 15:37:05 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_safe_atoi(char *npr, int flag)
{
	int		result;
	char	*to_compare;
	char	*aux;

	if (*npr == '+')
		aux = npr + 1;
	else
		aux = npr;
	result = ft_atoi(npr);
	to_compare = ft_itoa(result);
	if (ft_strncmp(aux, to_compare, ft_strlen(aux)) == 0)
		return (free(to_compare), result);
	else
	{
		flag = 1;
		free(to_compare);
		return (0);
	}
}

int	ft_fill(int *to_fill, char ***numbers, int size)
{
	int	i;
	int	j;
	int	k;
	int	flag;

	flag = 0;
	k = 0;
	i = 0;
	while (numbers[i] && k < size)
	{
		j = 0;
		while (numbers[i][j])
		{
			to_fill[k] = ft_safe_atoi(numbers[i][j], flag);
			if (flag)
				return (free(to_fill), ft_free_tpointer(numbers), 1);
			k++;
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_duplicates(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	*ft_generate_array(char ***numbers)
{
	int	*result;
	int	size;
	int	flag;

	flag = 0;
	size = ft_get_size(numbers);
	result = (int *)malloc(sizeof(int) * size);
	if (!result)
		return (0);
	ft_fill(result, numbers, size);
	flag = ft_check_duplicates(result, size);
	if (!flag)
	{
		ft_printf("There are duplicates!\n");
		return (free(result), NULL);
	}
	return (result);
}
