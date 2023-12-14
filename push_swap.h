/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:05:21 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/13 15:06:38 by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

int					ft_get_size(char ***numbers);
int					ft_is_valid(char c, int j);
char				***ft_group_args(int argc, char **argv);
int					ft_check_numbers(char ***to_check);
int					*ft_generate_array(char ***numbers);
int					ft_fill(int *to_fill, char ***numbers, int size);
int					ft_safe_atoi(char *npr, int flag);
void				ft_swap(int *a, int *b);
void				ft_bubble_sort(int *tab, int size);
int					*ft_numarray_dupe(int *array, int size);
t_stack				*ft_new_node(int content, int index, int *to_order);
void				ft_add_back(t_stack **lst, t_stack *new);
void				ft_clear_stack(t_stack **lst);
void				ft_show(t_stack *stack);

#endif