/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_b_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:14:28 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/18 13:24:50 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_stack_size(t_stack *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 1;
	while (lst->next != NULL)
	{
		lst = lst->next;
		count += 1;
	}
	return (count);
}

void	ft_update_index(t_stack **stack, int size)
{
	int	i;

	i = 0;
	while (*stack)
	{
		(*stack)->index = i;
		*stack = (*stack)->next;
		i++;
	}
}

void	ft_cost_b_first(t_stack **stack, int size)
{
	while (*stack)
	{
		if ((*stack)->index <= size / 2)
		{
			(*stack)->cost_b = (*stack)->index;
			(*stack)->direction_b = 1;
		}
		else
		{
			(*stack)->cost_b = size - (*stack)->index;
			(*stack)->direction_b = 0;
		}
	}
}

void	ft_cost_a_last(t_stack **stack, int size)
{
	while (*stack)
	{
		if ((*stack)->index < size / 2)
		{
			(*stack)->cost_a = (*stack)->index + 1;
			(*stack)->direction_a = 1;
		}
		else
		{
			(*stack)->cost_a = size - (*stack)->index - 1;
			(*stack)->direction_a = 0;
		}
	}
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
