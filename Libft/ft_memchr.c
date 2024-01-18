/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:52:25 by btan              #+#    #+#             */
/*   Updated: 2023/09/11 03:29:14 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *) s) == (unsigned char) c)
			return ((void *) s);
		s++;
		i++;
	}
	return (NULL);
}
/*{
	unsigned char	*ptr;

	ptr = (unsigned char *) s;
	while (*ptr != c && n--)
		ptr++;
	if (!*ptr && !c)
		return (ptr);
	if (!*ptr)
		return (NULL);
	return (ptr);
}*/
