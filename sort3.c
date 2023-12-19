/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:53:03 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/19 16:39:57 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_sort3(t_stack **stack_a)
{
	int	highest;
	int	lowest;

	highest = ft_find_highest(*stack_a);
	lowest = ft_find_lowest(*stack_a);
	if ((*stack_a)->target_pos == lowest)
	{
		if (((*stack_a)->next)->target_pos == highest)
			return (ft_reverse_rotate_a(stack_a), ft_swap_a(stack_a));
	}
	else if ((*stack_a)->target_pos == highest)
	{
		if (((*stack_a)->next)->target_pos == lowest)
			return (ft_rotate_a(stack_a));
		else
			return (ft_rotate_a(stack_a), ft_swap_a(stack_a));
	}
	else
	{
		if (((*stack_a)->next)->target_pos == lowest)
			return (ft_swap_a(stack_a));
		else
			return (ft_reverse_rotate_a(stack_a));
	}
}

int	ft_find_highest(t_stack *stack)
{
	int	result;

	result = stack->target_pos;
	while (stack)
	{
		if (stack->target_pos > result)
			result = stack->target_pos;
		stack = stack->next;
	}
	return (result);
}

int	ft_find_lowest(t_stack *stack)
{
	int	result;

	result = stack->target_pos;
	while (stack)
	{
		if (stack->target_pos < result)
			result = stack->target_pos;
		stack = stack->next;
	}
	return (result);
}
