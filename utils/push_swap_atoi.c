/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nando <nando@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 18:32:18 by nando             #+#    #+#             */
/*   Updated: 2025/03/26 16:50:34 by nando            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	skip_spaces(const char *nptr)
{
	int	i;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	return (i);
}

static int	is_valid_start_char(char c)
{
	if (!((c >= '0' && c <= '9') || c == '+' || c == '-'))
		return (ERROR);
	return (0);
}

static int	parse_sign(const char *nptr, int *i, int *sign)
{
	*sign = 1;
	if (nptr[*i] == '+' || nptr[*i] == '-')
	{
		if (nptr[*i + 1] < '0' || nptr[*i + 1] > '9')
			return (ERROR);
		if (nptr[*i] == '-')
			*sign = ERROR;
		(*i)++;
	}
	return (0);
}

static int	parse_number(const char *nptr, int *i, long *result, int sign)
{
	*result = 0;
	while (nptr[*i] >= '0' && nptr[*i] <= '9')
	{
		*result = *result * 10 + (nptr[*i] - '0');
		if (sign == 1 && *result > INT_MAX)
			return (ERROR);
		else if (sign == ERROR && -(*result) < INT_MIN)
			return (ERROR);
		(*i)++;
	}
	return (0);
}

int	push_swap_atoi(const char *nptr, int *num)
{
	int		i;
	int		sign;
	long	result;

	if (!nptr || !nptr[0])
		return (ERROR);
	i = skip_spaces(nptr);
	if (is_valid_start_char(nptr[i]) < 0)
		return (ERROR);
	if (parse_sign(nptr, &i, &sign) < 0)
		return (ERROR);
	if (parse_number(nptr, &i, &result, sign) < 0)
		return (ERROR);
	if (nptr[i] != '\0')
		return (ERROR);
	*num = (int)(sign * result);
	return (0);
}
