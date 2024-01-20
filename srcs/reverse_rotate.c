/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:31:15 by btan              #+#    #+#             */
/*   Updated: 2024/01/20 14:53:32 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **head_a)
{
	reverse_rotate(head_a);
	ft_printf("rra\n");
}

void	rrb(t_list **head_b)
{
	reverse_rotate(head_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **head_a, t_list **head_b)
{
	reverse_rotate(head_a);
	reverse_rotate(head_b);
	ft_printf("rrr\n");
}
