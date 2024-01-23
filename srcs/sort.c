/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:24:53 by btan              #+#    #+#             */
/*   Updated: 2024/01/23 22:46:16 by btan             ###   ########.fr       */
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
	int	a;
	int	b;
	int	c;

	a = ((t_content *)(*head)->content)->rank;
	b = ((t_content *)(*head)->next->content)->rank;
	c = ((t_content *)(*head)->next->next->content)->rank;
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

	b = ((t_content *)(*head_a)->next->content)->rank;
	c = ((t_content *)(*head_a)->next->next->content)->rank;
	d = ((t_content *)(*head_a)->next->next->next->content)->rank;
	min = stack_min(*head_a);
	if (d == min)
		rra(head_a);
	if (c == min)
		ra(head_a);
	b = ((t_content *)(*head_a)->next->content)->rank;
	if (b == min)
		sa(head_a);
	pb(head_a, head_b);
	sort3(head_a);
	pa(head_b, head_a);
}

void	sort5(t_list **head_a, t_list **head_b)
{
	int	b;
	int	c;
	int	d;
	int	e;
	int	min;

	b = ((t_content *)(*head_a)->next->content)->rank;
	c = ((t_content *)(*head_a)->next->next->content)->rank;
	d = ((t_content *)(*head_a)->next->next->next->content)->rank;
	e = ((t_content *)(*head_a)->next->next->next->next->content)->rank;
	min = stack_min(*head_a);
	if (d == min)
		rra(head_a);
	e = ((t_content *)(*head_a)->next->next->next->next->content)->rank;
	if (e == min)
		rra(head_a);
	if (c == min)
		ra(head_a);
	b = ((t_content *)(*head_a)->next->content)->rank;
	if (b == min)
		sa(head_a);
	pb(head_a, head_b);
	sort4(head_a, head_b);
	pa(head_b, head_a);
}

void	sort(t_list **head_a, t_list **head_b)
{
	t_list		*current;
	int			len;
	int			min;
	int			mid;
	int			midpoint;

	current = *head_a;
	len = ft_lstsize(*head_a);
	min = stack_min(*head_a);
	mid = stack_mid(*head_a);
	midpoint = 0;
	while (current)
	{
		if (((t_content *)current->content)->rank == mid && !midpoint)
			midpoint++;
		if (((t_content *)current->content)->rank == min && !midpoint)
			ra(head_a);
		if (((t_content *)current->content)->rank == min && midpoint)
			rra(head_a);
		if (((t_content *)(*head_a)->content)->rank == min)
		{
			pb(head_a, head_b);
			len--;
			break ;
		}
		current = current->next;
	}
	if (len > 5)
		sort(head_a, head_b);
	if (len == 5)
		sort5(head_a, head_b);
	if(len == 5 && is_sorted(*head_a))
		while (ft_lstsize(*head_b))
			pa(head_b, head_a);
}

