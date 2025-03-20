/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:07:55 by nando             #+#    #+#             */
/*   Updated: 2025/03/20 14:07:01 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack *init_stack(void)
{
	t_stack *stack = malloc(sizeof(t_stack));
	if(!stack)
		return (NULL);
	stack->top = NULL;
	stack->size = 0;
	return(stack);
}

t_node *create_node(int value)
{
	t_node *node = malloc(sizeof(t_node));
	if(!node)
		return (NULL);
	node->value = value;
	node->next = node;
	node->prev = node;
	return (node);
}

void push(t_stack *stack, int value)
{
    t_node *node = create_node(value);
    if (!node)
        return;
    if (stack->top == NULL)
        stack->top = node;
    else
    {
        t_node *last = stack->top->prev;
        node->next = stack->top;
        node->prev = last;
        last->next = node;
        stack->top->prev = node;
    }
    stack->size++;
}

int pop(t_stack *stack)
{
	int value;
	t_node *node;
	
	if(stack->top == NULL)
		return (ERROR);
	node = stack->top;
	value = node->value;
	if(stack->size == 1)
		stack->top = NULL;
	else
	{
		t_node *last = node->prev;
        t_node *new_top = node->next;
        last->next = new_top;
        new_top->prev = last;
        stack->top = new_top;
	}
	free(node);
	stack->size--;
	return (value);
}

void free_stack(t_stack *stack)
{
	ft_printf("**free_stack**\n");
	if(!stack)
		return ;
	while (stack->size > 0)
		pop(stack);
	free(stack);
}



