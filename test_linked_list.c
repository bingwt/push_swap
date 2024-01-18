/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_linked_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:22:59 by btan              #+#    #+#             */
/*   Updated: 2024/01/19 01:39:17 by btan             ###   ########.fr       */
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

int	main()
{
	t_list		*head_a;
	t_list		*node;
	t_content	*content1;

	content1 = ft_calloc(1, sizeof(t_content));
	content1->num = 5;
	head_a = ft_lstnew(content1);
	print_stack(head_a);

	t_content	*content2;

	content2 = ft_calloc(1, sizeof(t_content));
	content2->num = 1;
	node = ft_lstnew(content2);
	ft_lstadd_back(&head_a, node);
	print_stack(head_a);

	t_content	*content3;

	content3 = ft_calloc(1, sizeof(t_content));
	content3->num = 3;

	node = ft_lstnew(content3);
	ft_lstadd_back(&head_a, node);
	print_stack(head_a);

	t_list		*head_b;

	head_b = NULL;
	print_stack(head_a);
	print_stack(head_b);

	swap(&head_a);
	print_stack(head_a);
	print_stack(head_b);

	push(&head_a, &head_b);
	print_stack(head_a);
	print_stack(head_b);

	push(&head_a, &head_b);
	print_stack(head_a);
	print_stack(head_b);

	swap(&head_b);
	print_stack(head_a);
	print_stack(head_b);

	push(&head_b, &head_a);
	print_stack(head_a);
	print_stack(head_b);

	push(&head_b, &head_a);
	print_stack(head_a);
	print_stack(head_b);

	rotate(&head_a);
	print_stack(head_a);
	print_stack(head_b);

	reverse_rotate(&head_a);
	print_stack(head_a);
	print_stack(head_b);
	
}

// int	main()
// {
// 	t_list		*head;
// 	t_list		*node;
// 	t_content	*content1;
// 	t_content	*content2;

// 	content1 = ft_calloc(1, sizeof(t_content));
// 	content1->num = 5;
// 	content2 = ft_calloc(1, sizeof(t_content));
// 	content2->num = 1;
// 	head = ft_lstnew(content1);
// 	node = ft_lstnew(content2);
// 	ft_lstadd_back(&head, node);
// 	ft_printf("head: %d\n", ((t_content *)head->content)->num);
// 	ft_printf("node: %d\n", ((t_content *)head->next->content)->num);
// 	swap(head);
// 	ft_printf("head: %d\n", ((t_content *)head->content)->num);
// 	ft_printf("node: %d\n", ((t_content *)head->next->content)->num);
// }
