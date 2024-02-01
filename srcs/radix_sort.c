/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:48:11 by btan              #+#    #+#             */
/*   Updated: 2024/01/31 01:52:22 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(t_list *head)
{
	int	max;
	int	bits;

	max = stack_max(head);
	bits = 0;
	while (max)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static int	check_bit(int num, int pos)
{
	int	mask;

	mask = 1 << (pos - 1);
	return ((num & mask) != 0);
}

void	radix_sort(t_list **head_a, t_list **head_b)
{
	int	max_bit;
	int	bit;
	int	len;

	max_bit = max_bits(*head_a);
	bit = 0;
	while (bit <= max_bit)
	{
		len = ft_lstsize(*head_a);
		while (len--)
		{
			if (!check_bit(((t_content *)(*head_a)->content)->rank, bit))
				pb(head_a, head_b);
			else
				ra(head_a);
		}
		len = ft_lstsize(*head_b);
		while (len--)
			pa(head_b, head_a);
		bit++;
	}
}
