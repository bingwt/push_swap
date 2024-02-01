/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 14:54:02 by btan              #+#    #+#             */
/*   Updated: 2024/02/01 17:05:40 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_unique(t_list *head)
{
	int	len;
	int	seq_sum;
	int	sum;

	len = ft_lstsize(head);
	seq_sum = (len * (1 + len)) / 2;
	sum = 0;
	while (head)
	{
		sum += ((t_content *)head->content)->rank;
		head = head->next;
	}
	if (sum == seq_sum)
		return (1);
	return (0);
}

static int	check_sign(char **argv, int argc, int i)
{
	if (!ft_isdigit(argv[argc][i]) && argv[argc][i] != '-' && \
	argv[argc][i] != '+' && argv[argc][i] != ' ')
		return (1);
	if (ft_isdigit(argv[argc][i]) && \
	(argv[argc][i + 1] == '+' || argv[argc][i + 1] == '-'))
		return (1);
	if ((argv[argc][i] == '+' || argv[argc][i] == '-') && \
	(argv[argc][i + 1] == '+' || argv[argc][i + 1] == '-'))
		return (1);
	return (0);
}

static int	check_input(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		if (argc > 2 && ft_strchr(argv[i], ' '))
			return (1);
	while (--argc)
	{
		i = 0;
		if (argc > 2 && ft_strchr(argv[i], ' '))
			return (1);
		if (!ft_strlen(argv[argc]))
			return (1);
		while (argv[argc][i])
		{
			if (check_sign(argv, argc, i))
				return (1);
			i++;
		}
	}
	return (0);
}

static void	input_error(t_list **head)
{
	if (head)
		ft_lstclear(head, free);
	ft_printf("Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	t_list	*head_a;
	t_list	*head_b;
	char	**list;

	if (check_input(argc, argv))
		input_error(NULL);
	head_a = NULL;
	head_b = NULL;
	if (argc == 2)
	{
		list = ft_split(argv[1], ' ');
		init_stack(&head_a, argc, list);
		free_strs(list);
	}
	else
		init_stack(&head_a, argc, ++argv);
	init_rank(&head_a);
	if (!is_unique(head_a))
		input_error(&head_a);
	if (argc > 1 && !is_sorted(head_a))
		sort(&head_a, &head_b);
	ft_lstclear(&head_a, free);
	return (0);
}
