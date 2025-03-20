/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_pushes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:24:30 by nando             #+#    #+#             */
/*   Updated: 2025/03/17 14:35:48 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void    move_top(t_stack *src, t_stack *dst, t_node *move)
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
    if (dst->top == NULL)
    {
        dst->top = move;
        move->next = move;
        move->prev = move;
    }
    else
    {
        t_node *last = dst->top->prev;
        move->next = dst->top;
        move->prev = last;
        last->next = move;
        dst->top->prev = move;
        dst->top = move;
    }
    dst->size++;
}

void    pa(t_stack *a, t_stack *b)
{
    ft_printf("pa\n");
	if (!a || !b || b->size == 0)
		return;
	t_node *move = b->top;
	move_top(b, a, move);
}

void    pb(t_stack *a, t_stack *b)
{
    ft_printf("pb\n");
    if (!a || !b || a->size == 0)
        return;
    t_node *move = a->top;
    move_top(a, b, move);
}
