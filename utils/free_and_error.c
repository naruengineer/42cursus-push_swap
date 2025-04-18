/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 15:34:28 by nando             #+#    #+#             */
/*   Updated: 2025/04/18 16:37:38 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_tokens(char **tokens)
{
	int		i;

	i = 0;
	if (!tokens)
		return ;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

void	free_stack(t_stack *stack)
{
	if (!stack)
		return ;
	while (stack->size > 0)
		pop(stack);
	free(stack);
}

void	num_of_args_error(t_stack *stack_a, t_stack *stack_b, int *numbers)
{
	free(numbers);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	contents_error(t_stack *stack_a, t_stack *stack_b, int *numbers)
{
	ft_putstr_fd("Error\n", 2);
	free(numbers);
	free_stack(stack_a);
	free_stack(stack_b);
}
