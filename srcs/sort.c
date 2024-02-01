/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:24:53 by btan              #+#    #+#             */
/*   Updated: 2024/01/31 02:14:38 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort2(t_list **head)
{
	t_content	*a;
	t_content	*b;

	a = (*head)->content;
	b = (*head)->next->content;
	if (a->rank > b->rank)
		sa(head);
}

void	sort3(t_list **head)
{
	if (((t_content *)(*head)->content)->rank == stack_max(*head))
		ra(head);
	if (((t_content *)(*head)->next->content)->rank == stack_max(*head))
		rra(head);
	if (((t_content *)(*head)->content)->rank > \
	((t_content *)(*head)->next->content)->rank)
		sa(head);
}

void	sort4(t_list **head_a, t_list **head_b)
{
	if (((t_content *)(*head_a)->next->content)->rank == stack_min(*head_a))
		sa(head_a);
	else if (((t_content *)(*head_a)->next->next->content)->rank \
	== stack_min(*head_a))
	{
		ra(head_a);
		ra(head_a);
	}
	else if (((t_content *)(*head_a)->next->next->next->content)->rank \
	== stack_min(*head_a))
		rra(head_a);
	pb(head_a, head_b);
	sort3(head_a);
	pa(head_b, head_a);
}

void	sort5(t_list **head_a, t_list **head_b)
{
	if (((t_content *)(*head_a)->next->content)->rank == stack_min(*head_a))
		sa(head_a);
	else if (((t_content *)(*head_a)->next->next->content)->rank \
	== stack_min(*head_a))
	{
		ra(head_a);
		ra(head_a);
	}
	else if (((t_content *)(*head_a)->next->next->next->content)->rank \
	== stack_min(*head_a))
	{
		rra(head_a);
		rra(head_a);
	}
	else if (((t_content *)(*head_a)->next->next->next->next->content)->rank \
	== stack_min(*head_a))
		rra(head_a);
	pb(head_a, head_b);
	sort4(head_a, head_b);
	pa(head_b, head_a);
}

void	sort(t_list **head_a, t_list **head_b)
{
	if (ft_lstsize(*head_a) == 2)
		sort2(head_a);
	else if (ft_lstsize(*head_a) == 3)
		sort3(head_a);
	else if (ft_lstsize(*head_a) == 4)
		sort4(head_a, head_b);
	else if (ft_lstsize(*head_a) == 5)
		sort5(head_a, head_b);
	else if (ft_lstsize(*head_a) <= 215)
		chunk_sort(head_a, head_b);
	else if (ft_lstsize(*head_a) > 215)
		radix_sort(head_a, head_b);
}
