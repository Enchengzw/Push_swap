/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 12:54:08 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 12:54:11 by ezhou            ###   ########.fr       */
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
		ft_printf("Este es el nodo %d, su valor %d, posición deseada %d\n",
			stack->index, stack->value, stack->target_pos);
		ft_show(stack->next);
	}
}
