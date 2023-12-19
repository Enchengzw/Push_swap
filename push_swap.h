/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezhou <ezhou@student.42malaga.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:05:21 by ezhou             #+#    #+#             */
/*   Updated: 2023/12/19 15:37:55by ezhou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
// 1 is Rotate UP 0 is Reverse rotate DOWN
typedef struct s_stack
{
	int				value;
	int				index;
	int				target_pos;
	int				size;
	int				cost_a;
	int				cost_b;
	int				true_cost;
	int				direction_a;
	int				direction_b;
	struct s_stack	*next;
}					t_stack;

// PARSEO
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

// MOVIMIENTOS
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
void				ft_reverse_rotate_a(t_stack **a);
void				ft_reverse_rotate_b(t_stack **b);
void				ft_reverse_rotate_ab(t_stack **a, t_stack **b);
t_stack				*ft_penultimate(t_stack *lst);
int					ft_stack_size(t_stack *lst);

// COSTES
void				ft_update_index(t_stack *stack, int index, int size);
int					ft_find_node_index(int target_pos, t_stack *stack);
void				ft_cost_a_last(t_stack *stack, int size);
void				ft_cost_b_first(t_stack *stack, int size);
void				ft_cost_standard(t_stack *node, t_stack *stack, int size);
void				ft_cost_max(int max, t_stack *node, t_stack *stack,
						int size);
void				ft_cost_min(int min, t_stack *node, t_stack *stack,
						int size);
int					ft_find_min_max_index(t_stack *stack, int *min);
t_stack				*ft_find_minimum_higher_num(int num, t_stack *stack,
						int size);
void				ft_cost_a(t_stack *stack_a, t_stack *stack_b, int size_a);
void				ft_true_cost(t_stack *stack_b);

// ORDENACION

void				ft_sort3(t_stack **stack_a);
int					ft_find_highest(t_stack *stack);
int					ft_find_lowest(t_stack *stack);
void				ft_initialize_push_swap(t_stack **stack_a,
						t_stack **stack_b);
t_stack				*ft_find_lowest_cost_node(t_stack *stack_b);
void				ft_execute_single_a(t_stack **stack_a, t_stack *node);
void				ft_execute_single_b(t_stack **stack_b, t_stack *node);
void				ft_execute_commons(t_stack **stack_a, t_stack **stack_b,
						t_stack *node);
void				ft_execute_movements(t_stack **stack_a, t_stack **stack_b);

#endif