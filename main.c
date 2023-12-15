/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:38:23 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/15 16:07:23 by ezhou            ###   ########.fr       */
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
	b = NULL;
	a = ft_generate_stack(argc, argv);
	/*ft_push_b(&a, &b);
	ft_swap_a(&a);
	ft_rotate(&a);
	ft_reverse_rotate(&a);*/
	ft_show(a);
	ft_clear_stack(&a);
	ft_clear_stack(&b);
}
