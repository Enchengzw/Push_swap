/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:54:08 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/15 12:41:47 by ezhou            ###   ########.fr       */
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
		ft_printf("Nodo %d | valor %d | target_pos | %d | cost_a | %d | cost_b %d\n",
		 stack->index, stack->value, stack->target_pos, stack->cost_a,
			stack->cost_b);
		ft_show(stack->next);
	}
}
