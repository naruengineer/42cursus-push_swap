/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   few_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:31:25 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:20:29 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	two_args(t_stack *stack_a)
{
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a);
}

void	three_args(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	a = stack_a->top->value;
	b = stack_a->top->next->value;
	c = stack_a->top->next->next->value;
	if (a < b && b < c)
		return ;
	else if (a < b && a < c && b > c)
	{
		rra(stack_a);
		sa(stack_a);
	}
	else if (b < a && b < c && a < c)
		sa(stack_a);
	else if (b < a && b < c && a > c)
		ra(stack_a);
	else
	{
		if (a > b)
			sa(stack_a);
		rra(stack_a);
	}
}

void	four_args(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	three_args(stack_a);
	pa(stack_a, stack_b);
}

void	five_args(t_stack *stack_a, t_stack *stack_b)
{
	push_smallest_to_b(stack_a, stack_b);
	push_smallest_to_b(stack_a, stack_b);
	three_args(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	few_args_sort(t_stack *stack_a, t_stack *stack_b, const int count)
{
	if (count == 2)
		two_args(stack_a);
	else if (count == 3)
		three_args(stack_a);
	else if (count == 4)
		four_args(stack_a, stack_b);
	else
		five_args(stack_a, stack_b);
}
