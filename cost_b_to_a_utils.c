/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b_to_a_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 16:32:12 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/18 17:39:14 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_find_min_max_index(t_stack *stack, int *min)
{
	int	max;

	max = 0;
	while (stack)
	{
		if ((stack)->target_pos > max)
			max = (stack)->target_pos;
		if ((stack)->target_pos < *min)
			*min = (stack)->target_pos;
		stack = stack->next;
	}
	return (max);
}

void	ft_cost_max(int max, t_stack *node, t_stack *stack, int size)
{
	int	index;

	index = ft_find_node_index(max, stack);
	if (index >= size / 2)
	{
		node->cost_a = size - index - 1;
		node->direction_a = 0;
	}
	else
	{
		node->cost_a = index + 1;
		node->direction_a = 1;
	}
}

void	ft_cost_min(int min, t_stack *node, t_stack *stack, int size)
{
	int	index;

	index = ft_find_node_index(min, stack);
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

void	ft_cost_standard(t_stack *node, t_stack *stack, int max)
{
	t_stack	*aux;
	if (node->target_pos > 0)
	{
		aux = ft_find_minimum_higher_num(node->target_pos, stack, max);
		node->cost_a = aux->cost_a;
		node->direction_a = aux->direction_a;
	}
}

void	ft_cost_a(t_stack *stack_a, t_stack *stack_b, int size_a)
{
	int	min;
	int	max;

	min = stack_a->target_pos;
	if (!stack_b)
		return ;
	max = ft_find_min_max_index(stack_a, &min);
	if ((stack_b->target_pos) > max)
		ft_cost_max(max, stack_b, stack_a, size_a);
	else if ((stack_b->target_pos) < min)
		ft_cost_min(min, stack_b, stack_a, size_a);
	else
	{
		ft_cost_standard(stack_b, stack_a, max);
	}
	ft_cost_a(stack_a, stack_b->next, size_a);
}
