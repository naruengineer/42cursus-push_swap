/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:24:57 by nando             #+#    #+#             */
/*   Updated: 2025/04/20 15:25:56 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_count(t_stack *a, t_stack *b, int count, int *nums)
{
	if (count == ERROR)
	{
		contents_error(a, b, nums);
		return (ERROR);
	}
	if (count == 1)
	{
		num_of_args_error(a, b, nums);
		return (ERROR);
	}
	return (0);
}

static int	push_nums_to_stack_a(t_stack *stack_a, int count, int *nums)
{
	int	i;

	i = 0;
	while (i < count)
	{
		push(stack_a, nums[i]);
		i++;
	}
	return (0);
}

static void	sorts(t_stack *stack_a, t_stack *stack_b, int count)
{
	if (is_sorted(stack_a))
		return ;
	if (count <= 5)
		few_args_sort(stack_a, stack_b, count);
	else
		big_args_sort(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	int		*numbers;
	int		count;
	t_stack	*stack_a;
	t_stack	*stack_b;

	numbers = NULL;
	if (argc < 2)
		return (0);
	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (0);
	count = parse_input(argc, argv, &numbers);
	if (check_count(stack_a, stack_b, count, numbers) == ERROR)
		return (0);
	push_nums_to_stack_a(stack_a, count, numbers);
	free(numbers);
	sorts(stack_a, stack_b, count);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
