/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 01:29:55 by btan              #+#    #+#             */
/*   Updated: 2024/01/19 01:34:56 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
}

void	push(t_list **head_a, t_list **head_b)
{
	t_list	*node;

	if (*head_a == NULL)
		return ;
	node = *head_a;
	*head_a = (*head_a)->next;
	node->next = *head_b;
	*head_b = node;
}

void	rotate(t_list **head)
{
	t_list	*node;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	node = *head;
	*head = (*head)->next;
	node->next = NULL;
	ft_lstadd_back(head, node);
}

void	reverse_rotate(t_list **head)
{
	t_list	*node;
	t_list	*prev;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	node = *head;
	while (node->next)
	{
		prev = node;
		node = node->next;
	}
	prev->next = NULL;
	node->next = *head;
	*head = node;
}
