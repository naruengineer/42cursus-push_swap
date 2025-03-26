/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swaps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:54:46 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 17:04:15 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *a)
{
	t_node	*first;
	t_node	*second;

	ft_printf("sa\n");
	if (!a || a->size < 2)
		return ;
	first = a->top;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	first->prev->next = second;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	a->top = second;
}

void	sb(t_stack *b)
{
	t_node	*first;
	t_node	*second;

	ft_printf("sb\n");
	if (!b || b->size < 2)
		return ;
	first = b->top;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	first->prev->next = second;
	second->next->prev = first;
	second->next = first;
	first->prev = second;
	b->top = second;
}

void	ss(t_stack *a, t_stack *b)
{
	ft_printf("ss\n");
	sa(a);
	sb(b);
}
