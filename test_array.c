/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:22:59 by btan              #+#    #+#             */
/*   Updated: 2024/01/18 19:02:27 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *lst)
{
	ft_swap(&lst[0], &lst[1]);
}

void	push(int *lst_1, int *lst_2)
{
	ft_swap(&lst_1[0], &lst_2[0]);
}

int	main()
{
	int	*stack_a;
	int	*stack_b;

	stack_a = ft_calloc(3, sizeof(int *));
	stack_b = ft_calloc(3, sizeof(int *));
	stack_a[0] = 5;
	stack_a[1] = 1;
	stack_b[0] = 5;
	stack_b[1] = 1;
	ft_printf("stack_a: {%d, %d}\n", stack_a[0], stack_a[1]);
	ft_printf("stack_b: {%d, %d}\n", stack_b[0], stack_b[1]);
	swap(stack_a);
	swap(stack_b);
	ft_printf("stack_a: {%d, %d}\n", stack_a[0], stack_a[1]);
	ft_printf("stack_b: {%d, %d}\n", stack_b[0], stack_b[1]);
	push(stack_a, stack_b);
	ft_printf("stack_a: {%d, %d}\n", stack_a[0], stack_a[1]);
	ft_printf("stack_b: {%d, %d}\n", stack_b[0], stack_b[1]);
}	
