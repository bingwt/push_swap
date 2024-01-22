/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:24:53 by btan              #+#    #+#             */
/*   Updated: 2024/01/23 01:26:21 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_list **head)
{
	t_content	*a;
	t_content	*b;

	a = (*head)->content;
	b = (*head)->next->content;
	if (a->num > b->num)
		sa(head);
}

void	sort3(t_list **head)
{
	int	a;
	int	b;
	int	c;

	a = ((t_content *)(*head)->content)->num;
	b = ((t_content *)(*head)->next->content)->num;
	c = ((t_content *)(*head)->next->next->content)->num;
	if (a > b && a > c)
		ra(head);
	else if (a < b && a > c)
		rra(head);
	else
		sa(head);
	if (!is_sorted(*head))
		sort3(head);
}

void	sort4(t_list **head_a, t_list **head_b)
{
	int	b;
	int	c;
	int	d;
	int	min;

	b = ((t_content *)(*head_a)->next->content)->num;
	c = ((t_content *)(*head_a)->next->next->content)->num;
	d = ((t_content *)(*head_a)->next->next->next->content)->num;
	min = stack_min(*head_a);
	if (d ==min)
		rra(head_a);
	if (c == min)
		ra(head_a);
	b = ((t_content *)(*head_a)->next->content)->num;
	if (b == min)
		sa(head_a);
	pb(head_a, head_b);
	sort3(head_a);
	pa(head_b, head_a);
}
