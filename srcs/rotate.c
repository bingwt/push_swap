/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 21:28:24 by btan              #+#    #+#             */
/*   Updated: 2024/01/19 21:30:55 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **head_a)
{
	rotate(head_a);
	ft_printf("ra\n");
}

void	rb(t_list **head_b)
{
	rotate(head_b);
	ft_printf("rb\n");
}

void	rr(t_list **head_a, t_list **head_b)
{
	rotate(head_a);
	rotate(head_b);
	ft_printf("rr\n");
}
