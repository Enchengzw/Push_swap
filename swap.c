/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:22:50 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 18:09:44 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_swap_node(t_stack **stack)
{
	t_stack	*aux;
	t_stack	*third;

	third = ((*stack)->next)->next;
	aux = *stack;
	*stack = (*stack)->next;
	aux->next = third;
	(*stack)->next = aux;
}

void	ft_swap_a(t_stack **a)
{
	ft_swap_node(a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack **b)
{
	ft_swap_node(b);
	ft_printf("sb\n");
}

void	ft_swap_ab(t_stack **a, t_stack **b)
{
	ft_swap_node(a);
	ft_swap_node(b);
	ft_printf("ss\n");
}
