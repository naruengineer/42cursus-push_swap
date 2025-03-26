/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:42:27 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:20:32 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_max_bit_length(t_stack *stack)
{
	int		max;
	int		max_bit_len;
	long	value;

	max_bit_len = 0;
	max = (stack->size - 1);
	value = max;
	if (value == 0)
		return (1);
	while (value)
	{
		max_bit_len++;
		value = value >> 1;
	}
	return (max_bit_len);
}
