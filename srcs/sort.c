/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 21:24:53 by btan              #+#    #+#             */
/*   Updated: 2024/01/31 01:42:08 by btan             ###   ########.fr       */
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

void	simple_sort(t_list **head_a, t_list **head_b)
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
		simple_sort(head_a, head_b);
	if (len == 5)
		sort5(head_a, head_b);
	if(len == 5 && is_sorted(*head_a))
		while (ft_lstsize(*head_b))
			pa(head_b, head_a);
}

void	split_stack(t_list **head_a, t_list **head_b)
{
	int	len;
	int	midpoint;

	len = ft_lstsize(*head_a);
	midpoint = len / 2;
	while(len != midpoint)
	{
		pb(head_a, head_b);
		len--;
	}
}

// void	sort(t_list **head_a, t_list **head_b)
// {
// 	split_stack(head_a, head_b);
// 	// simple_sort(head_a, head_b);
// 	// while (ft_lstsize(*head_a) > 3)
// 	// {
// 	// 	pb(head_a, head_b);
// 	// }
// }

void	rotate_to_topa(t_list **head, int rank)
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
			ra(head);
		if (((t_content *)current->content)->rank == max && midpoint)
			rra(head);
		if (((t_content *)(*head)->content)->rank == rank)
			break ;
		current = current->next;
	}
}

void	rotate_to_topb(t_list **head, int rank)
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

void	cheapest_to_topa(t_list **head)
{
	init_cost(head);
	print_cost(*head, NULL);
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
	{
		len = ft_lstsize(*head_a);
		while (len--)
		{
			if (!ft_lstsize(*head_b))
				pb(head_a, head_b);
			if (((t_content *)(*head_a)->content)->rank <= current_chunk)
				pb(head_a, head_b);
			else
				ra(head_a);
			// if (((current_chunk / chunk_size) % 2) && current_chunk > chunk_size)
			// 		rb(head_b);
		}
		current_chunk += chunk_size;
	}
	len = ft_lstsize(*head_b);
	init_pos(head_b);
	while (len--)
	{
		while (((t_content *)(*head_b)->content)->rank != stack_max(*head_b))
			rotate_to_topb(head_b, stack_max(*head_b));
		pa(head_b, head_a);
	}
}

int	max_bits(t_list *head)
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

int check_bit(int num, int pos)
{
    int mask;
	
	mask = 1 << (pos - 1);
    return (num & mask) != 0;
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

void	sort(t_list **head_a, t_list **head_b)
{
	if (ft_lstsize(*head_a) == 2)
		sort2(head_a);
	if (ft_lstsize(*head_a) == 3)
		sort3(head_a);
	if (ft_lstsize(*head_a) == 4)
		sort4(head_a, head_b);
	if (ft_lstsize(*head_a) == 5)
		sort5(head_a, head_b);
	if (ft_lstsize(*head_a) <= 11)
		simple_sort(head_a, head_b);
	if (ft_lstsize(*head_a) <= 250)
		chunk_sort(head_a, head_b);
	if (ft_lstsize(*head_a) > 250)
		radix_sort(head_a, head_b);
}