/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:30:43 by btan              #+#    #+#             */
/*   Updated: 2024/01/23 03:04:14 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_list *head)
{
	int			min;
	t_content	*content;

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
	int			max;
	t_content	*content;

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
