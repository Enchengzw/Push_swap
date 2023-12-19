/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_movements.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:23:06 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/19 16:39:37 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_find_lowest_cost_node(t_stack *stack_b)
{
	t_stack	*lowest;

	lowest = stack_b;
	while (stack_b)
	{
		if (stack_b->true_cost < lowest->true_cost)
			lowest = stack_b;
		stack_b = stack_b->next;
	}
	return (lowest);
}

void	ft_execute_single_a(t_stack **stack_a, t_stack *node)
{
	int	counter;

	if (node->direction_a == node->direction_b)
		counter = node->cost_a - node->cost_b;
	else
		counter = node->cost_a;
	while (counter)
	{
		if (node->direction_a)
			ft_rotate_a(stack_a);
		else
			ft_reverse_rotate_a(stack_a);
		counter--;
	}
}

void	ft_execute_single_b(t_stack **stack_b, t_stack *node)
{
	int	counter;

	if (node->direction_a == node->direction_b)
		counter = node->cost_b - node->cost_a;
	else
		counter = node->cost_b;
	while (counter)
	{
		if (node->direction_b)
			ft_rotate_a(stack_b);
		else
			ft_reverse_rotate_a(stack_b);
		counter--;
	}
}

void	ft_execute_commons(t_stack **stack_a, t_stack **stack_b, t_stack *node)
{
	int	counter;
	int	direction;

	direction = node->direction_a;
	counter = node->cost_a;
	if (node->cost_a > node->cost_b)
		counter = node->cost_b;
	while (counter)
	{
		if (direction)
			ft_rotate_ab(stack_a, stack_a);
		else
			ft_reverse_rotate_ab(stack_a, stack_b);
		counter--;
	}
}

void	ft_execute_movements(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;

	node = ft_find_lowest_cost_node(*stack_b);
	if (node->direction_a == node->direction_b)
	{
		ft_execute_commons(stack_a, stack_b, node);
		if (node->cost_a > node->cost_b)
			ft_execute_single_a(stack_a, node);
		else
			ft_execute_single_b(stack_b, node);
	}
	else
	{
		ft_execute_single_a(stack_a, node);
		ft_execute_single_b(stack_b, node);
	}
	ft_push_a(stack_a, stack_b);
}
