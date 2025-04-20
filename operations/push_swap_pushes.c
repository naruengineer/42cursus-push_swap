/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pushes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:24:30 by nando             #+#    #+#             */
/*   Updated: 2025/04/12 17:34:00 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	pop_top(t_stack *src, t_node *move)
{
	if (src->size == 1)
		src->top = NULL;
	else
	{
		src->top = move->next;
		src->top->prev = move->prev;
		move->prev->next = src->top;
	}
	src->size--;
}

static void	push_top(t_stack *dst, t_node *move)
{
	t_node	*last;

	if (dst->top == NULL)
	{
		dst->top = move;
		move->next = move;
		move->prev = move;
	}
	else
	{
		last = dst->top->prev;
		move->next = dst->top;
		move->prev = last;
		last->next = move;
		dst->top->prev = move;
		dst->top = move;
	}
	dst->size++;
}

static void	move_top(t_stack *src, t_stack *dst, t_node *move)
{
	pop_top(src, move);
	push_top(dst, move);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*move;

	ft_printf("pa\n");
	if (!a || !b || b->size == 0)
		return ;
	move = b->top;
	move_top(b, a, move);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node	*move;

	ft_printf("pb\n");
	if (!a || !b || a->size == 0)
		return ;
	move = a->top;
	move_top(a, b, move);
}
