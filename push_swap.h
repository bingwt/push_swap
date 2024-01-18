/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:51:25 by btan              #+#    #+#             */
/*   Updated: 2024/01/19 01:31:25 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
#include <libft.h>

typedef struct	s_content
{
	int	num;
}	t_content;

void	swap(t_list **head);
void	push(t_list **head_a, t_list **head_b);
void	rotate(t_list **head);
void	reverse_rotate(t_list **head);

#endif
