/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:06:54 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 17:52:37 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	v;

	v = *a;
	*a = *b;
	*b = v;
}

void	ft_bubble_sort(int *tab, int size)
{
	int	i;
	int	j;

	size = size - 1;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab[j] > tab[j + 1])
			{
				ft_swap(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}

int	*ft_numarray_dupe(int *array, int size)
{
	int	i;
	int	*result;

	i = 0;
	result = (int *)malloc(sizeof(int) * size);
	if (!result)
		return (0);
	while (i < size)
	{
		result[i] = array[i];
		i++;
	}
	return (result);
}
