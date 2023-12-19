/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:54:08 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/19 15:57:12 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_show(t_stack *stack)
{
	if (stack == NULL)
		return ;
	else
	{
		ft_printf("Nodo %d | valor %d | target_pos | %d | cost_a | %d | cost_b %d | direction_a %d | direction_b %d | true_cost  %d\n",
		 stack->index, stack->value, stack->target_pos, stack->cost_a, stack->cost_b, stack->direction_a, stack->direction_b, stack->true_cost);
		ft_show(stack->next);
	}
}
