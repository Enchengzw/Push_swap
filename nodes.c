/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 13:19:21 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/13 14:31:58 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

/*typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}		t_stack;
*/

int	ft_find(int value, int *array)
{
	int	i;

	i = 0;
	while (value != array[i])
		i++;
	return (i);
}

t_stack	*ft_new_node(int content, int index, int *to_order)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = content;
	node->index = index;
	node->pos = index;
	node->target_pos = ft_find(content, to_order);
	node->cost_a = 0;
	node->cost_b = 0;
	node->next = NULL;
	return (node);
}

void	ft_add_back(t_stack **lst, t_stack *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		ft_add_back(&((*lst)->next), new);
}

void	ft_clear_stack(t_stack **lst)
{
	if (!lst || !(*lst))
		return ;
	ft_clear_stack(&((*lst)->next));
	free(*lst);
	*lst = NULL;
}
