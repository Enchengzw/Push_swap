/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:04:02 by ezhou             #+#    #+#             */
/*   Updated: 2023/11/30 12:03:11 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_stack *lst)
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
