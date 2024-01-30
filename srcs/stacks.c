/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:04:49 by btan              #+#    #+#             */
/*   Updated: 2024/01/30 13:46:51 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_list **head_a, char **argv)
{
	int			len;
	int			*ints;
	t_content	*content;
	t_list		*node;

	len = ft_strslen(argv);
	ints = strs_to_ints(argv);
	while (len--)
	{
		content = ft_calloc(1, sizeof(t_content));
		if (!content)
			return ;
		content->num = *ints;
		node = ft_lstnew(content);
		ft_lstadd_back(head_a, node);
		ints++;
	}
	free(ints - ft_strslen(argv));
}

void	init_rank(t_list **head)
{
	t_list	*node;
	int		rank;
	t_list	*temp;

	node = *head;
	while (node)
	{
		rank = 1;
		temp = *head;
		while (temp)
		{
			if (((t_content *)node->content)->num > \
				((t_content *)temp->content)->num)
				rank++;
			temp = temp->next;
		}
		((t_content *)node->content)->rank = rank;
		node = node->next;
	}
}

void	init_pos(t_list **head)
{
	int		pos;
	t_list	*node;

	pos = 1;
	node = *head;
	while (node)
	{
		((t_content *)node->content)->pos = pos;
		pos++;
		node = node->next;
	}
}

void	init_cost(t_list **head)
{
	t_list	*node;
	int		cost;

	node = *head;
	while (node)
	{
		cost = ((t_content *)node->content)->pos - \
				((t_content *)node->content)->rank;
		((t_content *)node->content)->cost = cost;
		node = node->next;
	}
}

int	is_sorted(t_list *head)
{
	t_list	*node;
	int		delta;

	node = head;
	while (node)
	{
		delta = 0;
		if (node->next)
			delta = ((t_content *) node->content)->rank - \
					((t_content *) node->next->content)->rank;
		if (delta > 0)
			return (0);
		node = node->next;
	}
	return (1);
}
