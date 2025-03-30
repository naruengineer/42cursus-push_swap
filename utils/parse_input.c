/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 17:46:37 by nando             #+#    #+#             */
/*   Updated: 2025/03/30 14:53:48 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	check_duplicate(int num, int *nums, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (num == nums[i])
			return (ERROR);
		i++;
	}
	return (0);
}

static int	check_and_store(const char *nptr, int *nums, int *count)
{
	int	num;

	if (push_swap_atoi(nptr, &num) < 0)
		return (ERROR);
	if (check_duplicate(num, nums, *count) < 0)
		return (ERROR);
	nums[*count] = num;
	(*count)++;
	return (0);
}

static int	parse_tokens(char **tokens, int token_count, int **nums)
{
	int	*input_numbers;
	int	count;
	int	i;

	input_numbers = malloc(sizeof(int) * token_count);
	if (!input_numbers)
	{
		free_tokens(tokens);
		return (ERROR);
	}
	count = 0;
	i = 0;
	while (i < token_count)
	{
		if (check_and_store(tokens[i], input_numbers, &count) < 0)
		{
			free_tokens(tokens);
			free(input_numbers);
			return (ERROR);
		}
		i++;
	}
	free_tokens(tokens);
	*nums = input_numbers;
	return (count);
}

static int	split_and_parse_single_arg(char *input, int **nums)
{
	char	**tokens;
	int		token_count;

	tokens = ft_split(input, ' ');
	token_count = 0;
	if (!tokens)
		return (ERROR);
	while (tokens[token_count])
		token_count++;
	return (parse_tokens(tokens, token_count, nums));
}

int	parse_input(int argc, char **argv, int **numbers)
{
	int	*nums;
	int	i;
	int	count;

	if (argc == 2)
		return (split_and_parse_single_arg(argv[1], numbers));
	i = 1;
	count = 0;
	nums = malloc(sizeof(int) * (argc - 1));
	if (!nums)
		return (ERROR);
	while (i < argc)
	{
		if (check_and_store(argv[i], nums, &count) < 0)
		{
			free(nums);
			return (ERROR);
		}
		i++;
	}
	*numbers = nums;
	return (count);
}
