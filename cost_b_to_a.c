/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:14:28 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/19 16:53:54 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_update_index(t_stack *stack, int index, int size)
{
	if (!stack)
		return ;
	else
	{
		stack->index = index;
		ft_update_index((stack->next), index + 1, size);
	}
}

void	ft_cost_b_first(t_stack *stack, int size)
{
	if (!stack)
		return;
	if ((stack)->index <= size / 2)
	{
		(stack)->cost_b = stack->index;
		(stack)->direction_b = 1;
	}
	else
	{
		(stack)->cost_b = size - stack->index;
		(stack)->direction_b = 0;
	}
	ft_cost_b_first((stack->next), size);
}

void	ft_cost_a_last2(t_stack *stack, int size)
{
	if (!stack)
		return ;
	if ((stack)->index < size / 2)
	{
		(stack)->cost_a = stack->index + 1;
		(stack)->direction_a = 1;
	}
	else
	{	
		(stack)->cost_a = size - stack->index - 1;
		(stack)->direction_a = 0;
	}
	ft_cost_a_last2((stack->next), size);
}

void	ft_cost_a_last(t_stack *stack, int size)
{
	if (!stack)
		return;
	if ((stack)->index <= size / 2)
	{
		(stack)->cost_a = stack->index;
		(stack)->direction_a = 1;
	}
	else
	{
		(stack)->cost_a = size - stack->index;
		(stack)->direction_a = 0;
	}
	ft_cost_a_last((stack->next), size);
}

int	ft_find_node_index(int target_pos, t_stack *stack)
{
	while (stack)
	{
		if (stack->target_pos == target_pos)
			return (stack->index);
		stack = stack->next;
	}
	return (0);
}

void	ft_true_cost(t_stack *stack_b)
{
	int	higher;
	int	lower;

	if (!stack_b)
		return ;
	higher = stack_b->cost_b;
	lower = stack_b->cost_a;
	if (stack_b->cost_a > stack_b->cost_b)
	{
		higher = stack_b->cost_a;
		lower = stack_b->cost_b;
	}
	if (stack_b->direction_a == stack_b->direction_b)
		stack_b->true_cost = higher + 1;
	else
		stack_b->true_cost = stack_b->cost_a + stack_b->cost_b + 1;
	ft_true_cost(stack_b->next);
}
