/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 20:23:06 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:20:35 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	search_smallest(t_stack *stack_a, int *smallest, int *posi)
{
	int		i;
	t_node	*tmp;

	i = 0;
	*smallest = stack_a->top->value;
	*posi = 0;
	tmp = stack_a->top;
	while (i < stack_a->size)
	{
		if (tmp->value < *smallest)
		{
			*smallest = tmp->value;
			*posi = i;
		}
		tmp = tmp->next;
		i++;
	}
}

void	push_smallest_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	smallest;
	int	posi;

	posi = 0;
	search_smallest(stack_a, &smallest, &posi);
	if (posi <= stack_a->size / 2)
	{
		while (posi-- > 0)
			ra(stack_a);
	}
	else
	{
		posi = stack_a->size - posi;
		while (posi-- > 0)
			rra(stack_a);
	}
	pb(stack_a, stack_b);
}

int	is_sorted(t_stack *stack)
{
	t_node	*current;
	int		i;

	i = 0;
	if (!stack || stack->size <= 1)
		return (1);
	current = stack->top;
	while (i < stack->size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}
