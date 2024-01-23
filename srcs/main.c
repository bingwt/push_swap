/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:54:02 by btan              #+#    #+#             */
/*   Updated: 2024/01/23 21:07:12 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	char	**list;
	int		len;

	head_a = NULL;
	head_b = NULL;
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		len = ft_strslen(list);
		init_stack(&head_a, list);
		free_strs(list);
	}
	else
	{
		len = ft_strslen(argv) - 1;
		init_stack(&head_a, ++argv);
	}
	init_rank(&head_a);
//	print_stacks(head_a, head_b);
//	print_ranks(head_a, head_b);
	if (argc > 1 && !is_sorted(head_a))
	{
		if (len == 2)
			sort2(&head_a);
		if (len == 3)
			sort3(&head_a);
		if (len == 4)
			sort4(&head_a, &head_b);
		if (len == 5)
			sort5(&head_a, &head_b);
		if (len > 5)
			sort(&head_a, &head_b);
	}
//	print_stacks(head_a, head_b);
//	print_ranks(head_a, head_b);
	if (is_sorted(head_a))
		//ft_printf("OK\n");
	ft_lstclear(&head_a, free);
	ft_lstclear(&head_b, free);
	return (0);
}
