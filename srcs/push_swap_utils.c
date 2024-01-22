/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 13:26:08 by btan              #+#    #+#             */
/*   Updated: 2024/01/23 03:16:38 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int		*ints;

	ptr = strs;
	ints = ft_calloc(ft_strslen(strs), sizeof(int));
	if (!ints)
		return (NULL);
	while (*ptr)
	{
		*ints = ft_atoi(*ptr);
		ints++;
		ptr++;
	}
	ints -= ft_strslen(strs);
	return (ints);
}
