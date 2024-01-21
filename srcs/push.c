/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:35:09 by btan              #+#    #+#             */
/*   Updated: 2024/01/21 17:53:10 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **head_b, t_list **head_a)
{
	push(head_b, head_a);
	ft_printf("pa\n");
}

void	pb(t_list **head_a, t_list **head_b)
{
	push(head_a, head_b);
	ft_printf("pb\n");
}
