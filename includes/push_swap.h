/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:51:25 by btan              #+#    #+#             */
/*   Updated: 2024/01/22 10:43:34 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <libft.h>

typedef struct s_content
{
	int	num;
}	t_content;

int		ft_strslen(char **strs);
int		*strs_to_ints(char **strs);

void	print_stack(t_list *head);
void	init_stack(t_list **head_a, char **argv);
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

void	sort2(t_list **head);
void	sort3(t_list **head);
void	sort4(t_list **head_a, t_list **head_b);

#endif
