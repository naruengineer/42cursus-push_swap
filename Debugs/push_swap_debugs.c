/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_debugs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:32:02 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:19:27 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stack(t_stack *stack, char *name)
{
	t_node	*current;
	int		count;

	if (!stack || !stack->top)
	{
		ft_printf("stack %s is empty. \n", name);
		return ;
	}
	current = stack->top;
	ft_printf("stack %s (size: %d)\n", name, stack->size);
	count = 0;
	while (count < stack->size)
	{
		ft_printf("[%d] ", current->value);
		current = current->next;
		count++;
	}
	ft_printf("\n");
}
