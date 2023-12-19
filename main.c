/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:38:23 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/19 16:51:32 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	leaks()
{
	system("leaks a.out");
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	//atexit(leaks);
	a = ft_generate_stack(argc, argv);
	b = NULL;
	ft_initialize_push_swap(&a, &b);
	ft_update_index(a, 0, ft_stack_size(a));
	ft_cost_a_last(a, ft_stack_size(a));
	ft_update_index(b, 0, ft_stack_size(b));
	ft_cost_b_first(b, ft_stack_size(b));
	ft_cost_a(a, b, ft_stack_size(a));
	ft_true_cost(b);
	ft_execute_movements(&a, &b);
	ft_update_index(a, 0, ft_stack_size(a));
	ft_cost_a_last(a, ft_stack_size(a));
	ft_printf("THIS IS A\n\n");
	ft_show(a);
	ft_update_index(b, 0, ft_stack_size(b));
	ft_cost_b_first(b, ft_stack_size(b));
	ft_cost_a(a, b, ft_stack_size(a));
	ft_true_cost(b);
	ft_printf("\n\nThis is B\n\n");
	ft_show(b);
	ft_clear_stack(&a);
	ft_clear_stack(&b);
}
