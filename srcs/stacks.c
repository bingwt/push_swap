/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:04:49 by btan              #+#    #+#             */
/*   Updated: 2024/01/21 17:22:10 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_list *head)
{
	t_list	*node;

	node = head;
	ft_printf("{");
	while (node)
	{
		ft_printf("%d", ((t_content *)node->content)->num);
		node = node->next;
		if (node)
			ft_printf(", ");
	}
	ft_printf("}\n");
}

void	init_stack(t_list **head_a, char **argv)
{
	int			*ints;
	int			len;
	t_list		*node;
	t_content	*content;

	len = ft_strslen(argv);
	ints = strs_to_ints(argv);
	while (len--)
	{
		content = ft_calloc(1, sizeof(t_content));
		content->num = *ints;
		node = ft_lstnew(content);
		ft_lstadd_back(head_a, node);
		ints++;
	}
	free(ints - ft_strslen(argv));
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
			delta = ((t_content *) node->content)->num - \
					((t_content *) node->next->content)->num;
		if (delta > 0)
			return (0);
		node = node->next;
	}
	return (1);
}
