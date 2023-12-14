/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:27:14 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 18:42:37 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_penultimate(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next && (lst->next)->next)
		lst = lst->next;
	return (lst);
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*penultimate;

	last = ft_last(*stack);
	penultimate = ft_penultimate(*stack);
	ft_add_front(stack, last);
	penultimate->next = NULL;
}

void	ft_revese_rotate_a(t_stack **a)
{
	ft_reverse_rotate(a);
	ft_printf("rra\n");
}

void	ft_revese_rotate_b(t_stack **b)
{
	ft_reverse_rotate(b);
	ft_printf("rrb\n");
}

void	ft_revese_rotate_a(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}
