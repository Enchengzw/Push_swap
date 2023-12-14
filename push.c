/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:29:59 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 18:40:32 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	ft_add_front(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
	{
		(new)->next = *lst;
		*lst = new;
	}
}

void	ft_push(t_stack **dst, t_stack **to_add)
{
	t_stack	*aux;

	aux = (*to_add)->next;
	(*to_add)->next = NULL;
	ft_add_front(dst, *to_add);
	*to_add = aux;
}

void	ft_push_b(t_stack **a, t_stack **b)
{
	ft_push(b, a);
	ft_printf("pb\n");
}

void	ft_push_a(t_stack **a, t_stack **b)
{
	ft_push(a, b);
	ft_printf("pa\n");
}
