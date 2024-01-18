/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:22:59 by btan              #+#    #+#             */
/*   Updated: 2024/01/18 20:04:35 by btan             ###   ########.fr       */
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

int	count_arr(char	**strs)
{
	char	**ptr;

	ptr = strs;
	while (*strs)
		strs++;
	return (strs - ptr);
}

int	*char_to_int(char *str)
{
	char	**char_arr;
	int		len;
	int		*int_arr;
	
	char_arr = ft_split(str, ' ');
	len = count_arr(char_arr);
	int_arr = ft_calloc(len, sizeof(int *));
	while (len--)
		int_arr[len] = ft_atoi(char_arr[len]);
	free_strs(char_arr);
	return (int_arr);
}

void	print_stacks(int *a, int *b)
{
	ft_printf("stack_a: {%d, %d, %d}\n", a[0], a[1], a[2]);
	ft_printf("stack_b: {%d, %d, %d}\n", b[0], b[1], b[2]);
}

int	main(int argc, char **argv)
{
	int	*stack_a;
	int	len;
	int	*stack_b;

	stack_a = char_to_int(argv[1]);
	len = 3;
	stack_b = ft_calloc(len, sizeof(int *));
	print_stacks(stack_a, stack_b);
}
//int	main(int argc, char **argv)
//{
//	int	*stack_a;
//	int	*stack_b;
//
//	if (argc != 2)
//		
//	stack_a = ft_calloc(3, sizeof(int *));
//	stack_b = ft_calloc(3, sizeof(int *));
//	stack_a[0] = 5;
//	stack_a[1] = 1;
//	stack_b[0] = 5;
//	stack_b[1] = 1;
//	ft_printf("stack_a: {%d, %d}\n", stack_a[0], stack_a[1]);
//	ft_printf("stack_b: {%d, %d}\n", stack_b[0], stack_b[1]);
//	swap(stack_a);
//	swap(stack_b);
//	ft_printf("stack_a: {%d, %d}\n", stack_a[0], stack_a[1]);
//	ft_printf("stack_b: {%d, %d}\n", stack_b[0], stack_b[1]);
//	push(stack_a, stack_b);
//	ft_printf("stack_a: {%d, %d}\n", stack_a[0], stack_a[1]);
//	ft_printf("stack_b: {%d, %d}\n", stack_b[0], stack_b[1]);
//}	
