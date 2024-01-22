/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 20:30:43 by btan              #+#    #+#             */
/*   Updated: 2024/01/22 21:07:23 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_min(t_list *head)
{
	int	min;
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
