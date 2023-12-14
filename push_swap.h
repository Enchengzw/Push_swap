/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:05:21 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/14 18:41:08 by ezhou            ###   ########.fr       */
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
	int				target_pos;
	int				size;
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
t_stack				*ft_new_node(int content, int index, int *to_order,
						int size);
void				ft_add_back(t_stack **lst, t_stack *new);
void				ft_clear_stack(t_stack **lst);
void				ft_show(t_stack *stack);
void				ft_add_front(t_stack **lst, t_stack *new);
t_stack				*ft_create_stack(int *unordered, int *ordered, int size);
t_stack				*ft_generate_stack(int argc, char **argv);
void				ft_push_a(t_stack **a, t_stack **b);
void				ft_push_b(t_stack **a, t_stack **b);
void				ft_push(t_stack **dst, t_stack **to_add);
void				ft_swap_node(t_stack **stack);
void				ft_swap_a(t_stack **a);
void				ft_swap_b(t_stack **a);
t_stack				*ft_last(t_stack *lst);
void				ft_rotate(t_stack **stack);
void				ft_rotate_a(t_stack **a);
void				ft_rotate_b(t_stack **b);
void				ft_rotate_ab(t_stack **a, t_stack **b);
void				ft_reverse_rotate(t_stack **stack);
t_stack				*ft_penultimate(t_stack *lst);

#endif