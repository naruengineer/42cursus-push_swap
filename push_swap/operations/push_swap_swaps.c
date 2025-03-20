/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swaps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:54:46 by nando             #+#    #+#             */
/*   Updated: 2025/03/11 16:37:05 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void sa(t_stack *a)
{
	ft_printf("sa\n");
	if(!a || a->size < 2)
		return;
	t_node *first = a->top;
	t_node *second = first->next;

	first->next = second->next;
	second->prev = first->prev;
	first->prev->next = second;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	a->top = second;
}

void sb(t_stack *b)
{
	ft_printf("sb\n");
	if(!b || b->size < 2)
		return;
	t_node *first = b->top;
	t_node *second = first->next;

	first->next = second->next;
	second->prev = first->prev;
	first->prev->next = second;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	b->top = second;
}

void ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	sa(a);
	sb(b);
}
