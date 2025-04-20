/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 13:55:38 by nando             #+#    #+#             */
/*   Updated: 2025/04/20 16:00:00 by nando            ###   ########.fr       */
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
void				free_tokens(char **tokens);
void				free_stack(t_stack *stack);
void				num_of_args_error(t_stack *stack_a, t_stack *stack_b,
						int *numbers);
void				contents_error(t_stack *stack_a, t_stack *stack_b,
						int *numbers);
int					push_swap_atoi(const char *nptr, int *num);
int					parse_input(int argc, char **argv, int **numbers);
int					is_sorted(t_stack *stack);
void				push_smallest_to_b(t_stack *stack_a, t_stack *stack_b);
void				few_args_sort(t_stack *stack_a, t_stack *stack_b,
						int count);
int					get_max_bit_length(t_stack *stack);
void				big_args_sort(t_stack *stack_a, t_stack *stack_b);

#endif