/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_push_swap.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:22:47 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/19 16:23:02 by ezhou            ###   ########.fr       */
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
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
		count += 1;
	}
	return (count);
}

void	ft_initialize_push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int		size;
	int		i;

	i = 0;
	size = ft_stack_size(*stack_a);
	while (i < (size - 3))
	{
		ft_push_b(stack_a, stack_b);
		i++;
	}
}
