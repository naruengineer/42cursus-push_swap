/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:07:55 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:47:41 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

void	push(t_stack *stack, int value)
{
	t_node	*node;
	t_node	*last;

	node = create_node(value);
	if (!node)
		return ;
	if (stack->top == NULL)
		stack->top = node;
	else
	{
		last = stack->top->prev;
		node->next = stack->top;
		node->prev = last;
		last->next = node;
		stack->top->prev = node;
	}
	stack->size++;
}

int	pop(t_stack *stack)
{
	int		value;
	t_node	*node;
	t_node	*last;
	t_node	*new_top;

	if (stack->top == NULL)
		return (ERROR);
	node = stack->top;
	value = node->value;
	if (stack->size == 1)
		stack->top = NULL;
	else
	{
		last = node->prev;
		new_top = node->next;
		last->next = new_top;
		new_top->prev = last;
		stack->top = new_top;
	}
	free(node);
	stack->size--;
	return (value);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->size > 0)
		pop(stack);
	free(stack);
}
