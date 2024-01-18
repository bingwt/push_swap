/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:22:59 by btan              #+#    #+#             */
/*   Updated: 2024/01/18 16:43:22 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *lst)
{
	int	*a;
	int	*b;

	a = (int *) lst->content;
	b = (int *) lst->next;
	ft_swap(a, b);
}

void	push(t_list *lst_1, t_list *lst_2)
{
	int	*a;
	int	*b;

	a = (int *) lst_1->content;
	b = (int *) lst_2->content;
	ft_swap(a, b);
}

int	main()
{
	t_list		*head;
	t_list		*node;
	t_content	*content1;
	t_content	*content2;

	content1 = ft_calloc(1, sizeof(t_content));
	content1->num = 5;
	content2 = ft_calloc(1, sizeof(t_content));
	content2->num = 1;
	head = ft_lstnew(content1);
	node = ft_lstnew(content2);
	ft_lstadd_back(&head, node);
	sort2(head);
}	
