/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:14:20 by nando             #+#    #+#             */
/*   Updated: 2025/03/11 16:36:50 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void ra(t_stack *a)
{
	ft_printf("ra\n");
	if(!a || a->size < 2)
		return;
	a->top = a->top->next;
}

void rb(t_stack *b)
{
	ft_printf("rb\n");
	if(!b || b->size < 2)
		return;
	b->top = b->top->next;
}

void rr(t_stack *a, t_stack *b)
{
	ft_printf("rr\n");
	ra(a);
	rb(b);
}
