/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:55:38 by nando             #+#    #+#             */
/*   Updated: 2025/04/18 18:05:54 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef ERROR
#  define ERROR -1
# endif

# include "libft/includes/ft_printf.h"
# include "libft/includes/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				n_rank;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

t_stack				*init_stack(void);
t_node				*create_node(int value);
void				push(t_stack *stack, int value);
int					pop(t_stack *stack);
void				free_tokens(char **tokens);
void				free_stack(t_stack *stack);
void				num_of_args_error(t_stack *stack_a, t_stack *stack_b,
						int *numbers);
void				contents_error(t_stack *stack_a, t_stack *stack_b,
						int *numbers);
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
int					push_swap_atoi(const char *nptr, int *num);
int					parse_input(int argc, char **argv, int **numbers);
void				search_smallest(t_stack *stack_a, int *smallest, int *posi);
void				push_smallest_to_b(t_stack *stack_a, t_stack *stack_b);
void				two_args(t_stack *stack_a);
void				three_args(t_stack *stack_a);
void				four_args(t_stack *stack_a, t_stack *stack_b);
void				five_args(t_stack *stack_a, t_stack *stack_b);
int					get_max_bit_length(t_stack *stack);
void				few_args_sort(t_stack *stack_a, t_stack *stack_b,
						int count);
void				big_args_sort(t_stack *stack_a, t_stack *stack_b);
int					is_sorted(t_stack *stack);

#endif