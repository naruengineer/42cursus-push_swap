/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:06:32 by nando             #+#    #+#             */
/*   Updated: 2025/04/20 16:11:30 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_int_array(int *arr, int n)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < n - 1)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	assign_ranks(t_stack *stack, int *arr, int s_size, t_node *node)
{
	int	i;
	int	rank;

	node = stack->top;
	i = 0;
	while (i < s_size)
	{
		rank = 0;
		while (rank < s_size)
		{
			if (node->value == arr[rank])
			{
				node->n_rank = rank;
				rank = s_size;
			}
			else
				rank++;
		}
		node = node->next;
		i++;
	}
}

static void	compress(t_stack *stack)
{
	int		s_size;
	int		*array;
	t_node	*node;
	int		i;

	s_size = stack->size;
	array = malloc(sizeof(int) * s_size);
	if (!array)
		return ;
	node = stack->top;
	i = 0;
	while (i < s_size)
	{
		array[i] = node->value;
		node = node->next;
		i++;
	}
	sort_int_array(array, s_size);
	assign_ranks(stack, array, s_size, node);
	free(array);
}

static void	radix_sort(t_stack *stack_a, t_stack *stack_b, int max_bit_len)
{
	long	current_rank;
	int		size_a;
	int		i;
	int		j;

	i = 0;
	while (i < max_bit_len)
	{
		size_a = stack_a->size;
		j = 0;
		while (j < size_a)
		{
			current_rank = stack_a->top->n_rank;
			if (((current_rank >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}

void	big_args_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bit_len;

	compress(stack_a);
	max_bit_len = get_max_bit_length(stack_a);
	radix_sort(stack_a, stack_b, max_bit_len);
}
