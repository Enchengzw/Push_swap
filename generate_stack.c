/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:20:32 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 13:05:24 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack	*ft_create_stack(int *unordered, int *ordered, int size)
{
	int		i;
	t_stack	*aux;
	t_stack	*start;

	start = NULL;
	i = 0;
	while (i < size)
	{
		aux = ft_new_node(unordered[i], i, ordered);
		if (!aux)
			return (ft_clear_stack(&start), NULL);
		ft_add_back(&start, aux);
		i++;
	}
	return (start);
}

t_stack	*ft_generate_stack(int argc, char **argv)
{
	char	***aux;
	int		*array;
	int		*to_order;
	t_stack	*stack;

	aux = ft_group_args(argc, argv);
	if (!aux)
		return (0);
	if (!ft_check_numbers(aux))
		return (ft_free_tpointer(aux), NULL);
	array = ft_generate_array(aux);
	if (!array)
		return (ft_free_tpointer(aux), NULL);
	to_order = ft_numarray_dupe(array, ft_get_size(aux));
	if (!to_order)
		return (ft_free_tpointer(aux), free(array), NULL);
	ft_bubble_sort(to_order, ft_get_size(aux));
	stack = ft_create_stack(array, to_order, ft_get_size(aux));
	if (!stack)
		return (ft_free_tpointer(aux), free(array), free(to_order), NULL);
	return (free(array), free(to_order), ft_free_tpointer(aux), stack);
}

void	leaks()
{
	system("leaks a.out");
}

int main(int argc, char **argv)
{
	t_stack *a;

	atexit(leaks);
	a = ft_generate_stack(argc, argv);
	ft_show(a);
	ft_clear_stack(&a);
}
