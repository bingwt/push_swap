/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:26:08 by btan              #+#    #+#             */
/*   Updated: 2024/01/31 20:08:40 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

long	ft_atol(const char *str)
{
	long	i;
	long	value;
	long	neg;

	i = 0;
	value = 0;
	neg = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -neg;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (value * neg);
		value = value * 10 + str[i] - '0';
		i++;
	}
	return (value * neg);
}

int	ft_strslen(char **strs)
{
	char	**ptr;

	ptr = strs;
	while (*ptr)
		ptr++;
	return (ptr - strs);
}

int	*strs_to_ints(char **strs)
{
	char	**ptr;
	long	num;
	int		*ints;
	int		*temp;

	ptr = strs;
	ints = ft_calloc(ft_strslen(strs), sizeof(int));
	if (!ints)
		return (NULL);
	temp = ints;
	while (*ptr)
	{
		num = ft_atol(*ptr);
		if (num > 2147483647 || num < -2147483648)
		{
			free(temp);
			return (NULL);
		}
		*ints = ft_atoi(*ptr);
		ints++;
		ptr++;
	}
	ints -= ft_strslen(strs);
	return (ints);
}
