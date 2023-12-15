/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_min_max.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:32:12 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/15 17:43:50 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_find_min_max(t_stack *stack, int *min)
{
	int	max;

	max = 0;
	while (stack)
	{
		if ((stack)->target_pos > max)
			max = (stack)->target_pos;
		if ((stack)->target_pos < *min)
			*min = (stack)->target_pos;
	}
	return (max);
}

int	ft_find_node(int target_pos, t_stack *stack)
{
	while (stack)
	{
		if (stack->target_pos == target_pos)
			return (stack->index);
		stack = stack->next;
	}
	return (0);
}

void	ft_cost_max(int max, t_stack *node, int size)
{
	int	index;

	index = ft_find_node(max, node);
	if (index >= size / 2)
	{
		node->cost_a = size - index -1;
		node->direction_a = 0;
	}
	else
	{
		node->cost_a = index + 1;
		node->direction_a = 1;
	}
}

void	ft_cost_min(int min, t_stack *node, int size)
{
	int	index;

	index = ft_find_node(min, node);
	if (index <= size / 2)
	{
		node->cost_a = index;
		node->direction_a = 1;
	}
	else
	{
		node->cost_a = size - index;
		node->direction_a = 0;
	}
}

void	ft_find_cost(t_stack **stack, t_stack *node, int size)
{
	int	min;
	int	max;

	min = 0;
	max = ft_find_min_max_index(*stack, &min);
	if (node->target_pos > max)
		ft_cost_max(max, node, size);
	else if (node->target_pos < min)
		ft_cost_min(min, node, size);
	else
	{
		ft_cost_standard(min, node, size);
	}
}
