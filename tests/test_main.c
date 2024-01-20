/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:22:59 by btan              #+#    #+#             */
/*   Updated: 2024/01/20 14:48:25 by btan             ###   ########.fr       */
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

void	init_stack(t_list **head_a, t_list **head_b, char **argv)
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

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc > 1)
	{
		init_stack(&head_a, &head_b, ++argv);
		print_stack(head_a);
		print_stack(head_b);
		swap(&head_a);
		print_stack(head_a);
		print_stack(head_b);
		push(&head_a, &head_b);
		print_stack(head_a);
		print_stack(head_b);

		ft_lstclear(&head_a, free);
		ft_lstclear(&head_b, free);
	}
	return (0);
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
