/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:51:25 by btan              #+#    #+#             */
/*   Updated: 2024/01/26 14:03:50 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>

typedef struct s_content
{
	int	num;
	int	rank;
	int	pos;
	int	cost;
}	t_content;

long	ft_atol(const char *str);
int		ft_strslen(char **strs);
int		*strs_to_ints(char **strs);

void	print_stacks(t_list *head_a, t_list *head_b);
void	print_ranks(t_list *head_a, t_list *head_b);
void	print_pos(t_list *head_a, t_list *head_b);
void	print_cost(t_list *head_a, t_list *head_b);
void	init_stack(t_list **head_a, char **argv);
void	init_rank(t_list **head);
void	init_pos(t_list **head);
void	init_cost(t_list **head);
int		is_sorted(t_list *head);

void	swap(t_list **head);
void	push(t_list **head_a, t_list **head_b);
void	rotate(t_list **head);
void	reverse_rotate(t_list **head);

void	sa(t_list **head_a);
void	sb(t_list **head_b);
void	ss(t_list **head_a, t_list **head_b);

void	pa(t_list **head_a, t_list **head_b);
void	pb(t_list **head_a, t_list **head_b);

void	ra(t_list **head_a);
void	rb(t_list **head_b);
void	rr(t_list **head_a, t_list **head_b);

void	rra(t_list **head_a);
void	rrb(t_list **head_b);
void	rrr(t_list **head_a, t_list **head_b);

int		stack_min(t_list *head);
int		stack_max(t_list *head);
int		stack_mid(t_list *head);

void	sort2(t_list **head);
void	sort3(t_list **head);
void	sort4(t_list **head_a, t_list **head_b);
void	sort5(t_list **head_a, t_list **head_b);
void	simple_sort(t_list **head_a, t_list **head_b);
void	sort(t_list **head_a, t_list **head_b);

#endif
