/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:04:49 by btan              #+#    #+#             */
/*   Updated: 2024/01/23 03:15:33 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_list *head_a, t_list *head_b)
{
	t_list	*a;
	t_list	*b;

	a = head_a;
	b = head_b;
	ft_printf("Stack A\t Stack B\n");
	while (a)
	{
		ft_printf("   %d\t    ", ((t_content *)a->content)->num);
		a = a->next;
		if (b)
		{
			ft_printf("%d", ((t_content *)b->content)->num);
			b = b->next;
		}
		if (a)
			ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_ranks(t_list *head_a, t_list *head_b)
{
	t_list	*a;
	t_list	*b;

	a = head_a;
	b = head_b;
	ft_printf("Stack A\t Stack B\n");
	while (a)
	{
		ft_printf("   %d\t    ", ((t_content *)a->content)->rank);
		a = a->next;
		if (b)
		{
			ft_printf("%d", ((t_content *)b->content)->rank);
			b = b->next;
		}
		if (a)
			ft_printf("\n");
	}
	ft_printf("\n");
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
	t_list	*temp;
	int		rank;

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
