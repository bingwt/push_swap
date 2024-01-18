/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:22:59 by btan              #+#    #+#             */
/*   Updated: 2024/01/18 18:07:53 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *lst)
{
	ft_swap(&lst[0], &lst[1]);
}

void	push(int *lst_1, int *lst_2)
{
	ft_swap(&lst_1[0], &lst_2[0])
}

int	main()
{
	int	*stack_a;
	int	*stack_b;

	stack_a = ft_calloc(3, sizeof(int *));
	stack_b = ft_calloc(3, sizeof(int *));
	stack_a[0] = 5;
	stack_a[1] = 1;
	swap(stack_a);
	ft_printf("%d\n", stack_a[0]);
}	
