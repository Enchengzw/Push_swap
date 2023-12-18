/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b_to_a_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 13:01:32 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/18 13:08:58 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_find_minimum_higher_num(int num, t_stack *stack, int size)
{
	t_stack	*result;
	int		aux;

	aux = size;
	result = 0;
	while (stack)
	{
		if (stack->target_pos > num)
		{
			if (stack->target_pos - num < aux)
			{
				aux = stack->target_pos - num;
				result = stack;
			}
		}
		stack = stack->next;
	}
	return (result);
}
