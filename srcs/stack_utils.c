/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 02:41:19 by btan              #+#    #+#             */
/*   Updated: 2024/01/31 02:02:29 by btan             ###   ########.fr       */
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
	while (a || b)
	{
		if (a)
		{
			ft_printf("   %d\t    ", ((t_content *)a->content)->rank);
			a = a->next;
		}
		else
			ft_printf("   \t    ");
		if (b)
		{
			ft_printf("%d", ((t_content *)b->content)->rank);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}

void	print_pos(t_list *head_a, t_list *head_b)
{
	t_list	*a;
	t_list	*b;

	a = head_a;
	b = head_b;
	ft_printf("Stack A\t Stack B\n");
	while (a || b)
	{
		if (a)
		{
			ft_printf("   %d\t    ", ((t_content *)a->content)->pos);
			a = a->next;
		}
		else
			ft_printf("   \t    ");
		if (b)
		{
			ft_printf("%d", ((t_content *)b->content)->pos);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("\n");
}
