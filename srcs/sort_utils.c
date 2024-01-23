/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:30:43 by btan              #+#    #+#             */
/*   Updated: 2024/01/23 13:17:54 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_list *head)
{
	t_content	*content;
	int			min;

	content = head->content;
	min = content->num;
	while (head)
	{
		content = head->content;
		if (content->num < min)
			min = content->num;
		head = head->next;
	}
	return (min);
}

int	stack_max(t_list *head)
{
	t_content	*content;
	int			max;

	content = head->content;
	max = content->num;
	while (head)
	{
		content = head->content;
		if (content->num > max)
			max = content->num;
		head = head->next;
	}
	return (max);
}

int	stack_mid(t_list *head)
{
	int			mid;
	t_content	*content;

	mid = ft_lstsize(head) / 2;
	while (mid--)
		head = head->next;
	content = head->content;
	return (content->num);
}
