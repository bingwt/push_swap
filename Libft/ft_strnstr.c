/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 01:32:36 by btan              #+#    #+#             */
/*   Updated: 2023/09/11 17:45:07 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return (big);
	while (big[i] != '\0' && i < len)
	{
		while (big[i + j] == little[j] && (i + j) < len && big[i + j])
			j++;
		if (little[j] == '\0')
			return (big + i);
		i++;
		j = 0;
	}
	return (0);
}
