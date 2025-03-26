/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_reverse_rotates.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:27:41 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:20:13 by nando            ###   ########.fr       */
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

void	rrr(t_stack *a, t_stack *b)
{
	ft_printf("rrr\n");
	rra(a);
	rrb(b);
}
