/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:33:36 by btan              #+#    #+#             */
/*   Updated: 2024/01/19 01:37:18 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **head_a)
{
	swap(head_a);
	ft_printf("sa\n");
}

void	sb(t_list **head_b)
{
	swap(head_b);
	ft_printf("sb\n");
}

void	ss(t_list **head_a, t_list **head_b)
{
	swap(head_a);
	swap(head_b);
	ft_printf("ss\n");
}
