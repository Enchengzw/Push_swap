/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:09:58 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 18:25:56 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_last(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*second;
	t_stack	*last;

	last = ft_last(*stack);
	second = (*stack)->next;
	(*stack)->next = NULL;
	last->next = *stack;
	*stack = second;
}

void	ft_rotate_a(t_stack **a)
{
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_stack **b)
{
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ft_rotate_ab(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
