/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 13:26:03 by btan              #+#    #+#             */
/*   Updated: 2023/09/11 16:25:51 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest > src)
	{
		while (n--)
		{
			((unsigned char *) dest)[n] = ((unsigned char *) src)[n];
			if (!n)
				return (dest);
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <stdio.h>
#include <string.h>
int	main()
{
	int src[5] = {0, 1, 2, 3, 4};
	int dest[5];
	size_t n = 5;

	ft_memmove(dest, src, n);
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", src[i]);
		printf("%d\n", dest[i]);
	}
}*/
