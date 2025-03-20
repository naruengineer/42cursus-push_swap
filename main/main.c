/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:24:57 by nando             #+#    #+#             */
/*   Updated: 2025/03/20 15:21:02 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


static int checks(t_stack *stack_a, t_stack *stack_b, int count, int *numbers)
{
	int i;
	
	if (count == ERROR)
	{
		ft_printf("Please check args and try again.\n");
		return (ERROR);
	}
	if (!stack_a || !stack_b)
	{
		ft_printf("Error\n");
		return (ERROR);
	}
	ft_printf("\nInput %d numbers\n", count);
	i = 0;
	while (i < count)
	{
		push(stack_a, numbers[i]);
		ft_printf("push[%d] : %d\n", i, numbers[i]);
		i++;
	}
	return (0);
}

static void sorts(t_stack *stack_a, t_stack *stack_b, int count)
{
	ft_printf("\n*********Before*********\n");
	print_stack(stack_a, "a");
	print_stack(stack_b, "b");
	if(is_sorted(stack_a))
	{
		ft_printf("\nAlready sorted.\n\n");
		return;
	}
	ft_printf("\n*************************\n");
	ft_printf("\nSorting...\n");
	if(count <= 5)
		few_args_sort(stack_a, stack_b, count);
	else
		big_args_sort(stack_a, stack_b);
	ft_printf("Finish!!!\n");
	ft_printf("\n**********After**********\n");
	print_stack(stack_a,"a");
	print_stack(stack_b,"b");
	ft_printf("\n*************************\n");
}

int main(int argc, char **argv)
{
    int *numbers;
    int count;
	t_stack *stack_a;
	t_stack *stack_b;

	if(argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
    count = parse_input(argc, argv, &numbers);
	if(count == 1)
		return (0);
	if(checks(stack_a, stack_b, count, numbers) == ERROR)
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	free(numbers);
	//ft_printf("\n**free_numbers**\n");
	sorts(stack_a, stack_b, count);
	free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}
