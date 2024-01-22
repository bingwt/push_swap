/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:54:02 by btan              #+#    #+#             */
/*   Updated: 2024/01/23 01:22:34 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	char	**list;
	int		len;
	char	move[100];
	int		min;

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
	system("clear");
	ft_printf("Inital Stacks:\n");
	print_stacks(head_a, head_b);
	min = stack_min(head_a);
	ft_printf("min: %d\n", min);
	while(1)
	{
		ft_printf("Enter move: ");
		scanf("%s", move);
		if (!strncmp(move, "sa", 2))
			sa(&head_a);
		if (!strncmp(move, "sb", 2))
			sb(&head_b);
		if (!strncmp(move, "ss", 2))
			ss(&head_a, &head_b);
		if (!strncmp(move, "pa", 2))
			pa(&head_b, &head_a);
		if (!strncmp(move, "pb", 2))
			pb(&head_a, &head_b);
		if (!strncmp(move, "ra", 2))
			ra(&head_a);
		if (!strncmp(move, "rb", 2))
			rb(&head_b);
		if (!strncmp(move, "rr", 2) && !move[2])
			rr(&head_a, &head_b);
		if (!strncmp(move, "rra", 3))
			rra(&head_a);
		if (!strncmp(move, "rrb", 3))
			rrb(&head_b);
		if (!strncmp(move, "rrr", 3))
			rrr(&head_a, &head_b);
		if (!strncmp(move, "sort2", 5))
			sort2(&head_a);
		if (!strncmp(move, "sort3", 5))
			sort3(&head_a);
		print_stacks(head_a, head_b);
	}
	ft_lstclear(&head_a, free);
	ft_lstclear(&head_b, free);
	return (0);
}
