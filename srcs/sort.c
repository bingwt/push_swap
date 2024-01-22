/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:24:53 by btan              #+#    #+#             */
/*   Updated: 2024/01/22 12:44:22 by btan             ###   ########.fr       */
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
	else if (!is_sorted(*head))
		sa(head);
	if (!is_sorted(*head))
		sort3(head);
}

void	sort4(t_list **head_a, t_list **head_b)
{
	int	aa;
	int	ab;
	int	ac;
	int	ba;

	pb(head_a, head_b);
	sort3(head_a);
	aa = ((t_content *)(*head_a)->content)->num;
	ab = ((t_content *)(*head_a)->next->content)->num;
	ac = ((t_content *)(*head_a)->next->next->content)->num;
	ba = ((t_content *)(*head_b)->content)->num;
	pa(head_b, head_a);
	if (ba > ac)
		ra(head_a);
	if (ba > ab && !is_sorted(*head_a))
	{
		rra(head_a);
		sa(head_a);
		ra(head_a);
		ra(head_a);
	}
	if (ba > aa && !is_sorted(*head_a))
		sa(head_a);
}
