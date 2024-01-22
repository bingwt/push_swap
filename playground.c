/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playground.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:54:02 by btan              #+#    #+#             */
/*   Updated: 2024/01/22 18:02:44 by btan             ###   ########.fr       */
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
	while(1)
	{
		ft_printf("Enter move: ");
		scanf("%s", move);
		if (!strncmp(move, "sa", 2))
			sa(&head_a);
		else if (!strncmp(move, "ra", 2))
			ra(&head_a);
		print_stacks(head_a, head_b);
	}
	ft_lstclear(&head_a, free);
	ft_lstclear(&head_b, free);
	return (0);
}
