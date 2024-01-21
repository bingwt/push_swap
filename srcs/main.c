/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:54:02 by btan              #+#    #+#             */
/*   Updated: 2024/01/21 17:27:53 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	char	**list;

	head_a = NULL;
	head_b = NULL;
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		init_stack(&head_a, list);
		free_strs(list);
	}
	else
		init_stack(&head_a, ++argv);
	if (argc > 1)
	{
		print_stack(head_a);
		print_stack(head_b);
		ft_printf("%d\n", is_sorted(head_a));
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
