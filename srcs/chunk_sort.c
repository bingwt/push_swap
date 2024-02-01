/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:50:08 by btan              #+#    #+#             */
/*   Updated: 2024/01/31 18:23:33 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_to_topb(t_list **head, int rank)
{
	t_list		*current;
	int			max;
	int			mid;
	int			midpoint;

	current = *head;
	max = stack_max(*head);
	mid = stack_mid(*head);
	midpoint = 0;
	while (current)
	{
		if (((t_content *)current->content)->rank == mid && !midpoint)
			midpoint++;
		if (((t_content *)current->content)->rank == max && !midpoint)
			rb(head);
		if (((t_content *)current->content)->rank == max && midpoint)
			rrb(head);
		if (((t_content *)(*head)->content)->rank == rank)
			break ;
		current = current->next;
	}
}

void	chunk_to_b(t_list **head_a, t_list **head_b, \
int *current_chunk, int chunk_size)
{
	int	len;

	len = ft_lstsize(*head_a);
	while (len--)
	{
		if (!ft_lstsize(*head_b))
			pb(head_a, head_b);
		if (((t_content *)(*head_a)->content)->rank <= *current_chunk)
			pb(head_a, head_b);
		else
			ra(head_a);
	}
	*current_chunk += chunk_size;
}

void	chunk_sort(t_list **head_a, t_list **head_b)
{
	int	chunk_size;
	int	chunks;
	int	remainder;
	int	current_chunk;
	int	len;

	chunk_size = 10;
	if (ft_lstsize(*head_a) < 12)
		chunk_size = 3;
	chunks = ft_lstsize(*head_a) / chunk_size;
	remainder = ft_lstsize(*head_a) % chunk_size;
	if (remainder)
		chunks++;
	current_chunk = chunk_size;
	while (current_chunk <= (chunks * 10))
		chunk_to_b(head_a, head_b, &current_chunk, chunk_size);
	len = ft_lstsize(*head_b);
	init_pos(head_b);
	while (len--)
	{
		while (((t_content *)(*head_b)->content)->rank != stack_max(*head_b))
			rotate_to_topb(head_b, stack_max(*head_b));
		pa(head_b, head_a);
	}
}
