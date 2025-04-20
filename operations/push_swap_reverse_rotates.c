/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:41 by nando             #+#    #+#             */
/*   Updated: 2025/04/20 15:06:50 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a)
{
	ft_printf("rra\n");
	if (!a || a->size < 2)
		return ;
	a->top = a->top->prev;
}

void	rrb(t_stack *b)
{
	ft_printf("rrb\n");
	if (!b || b->size < 2)
		return ;
	b->top = b->top->prev;
}

static void	rrr_a(t_stack *a)
{
	if (!a || a->size < 2)
		return ;
	a->top = a->top->prev;
}

static void	rrr_b(t_stack *b)
{
	if (!b || b->size < 2)
		return ;
	b->top = b->top->prev;
}

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	rrr_a(a);
	rrr_b(b);
}
