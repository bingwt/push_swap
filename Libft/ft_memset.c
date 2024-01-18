/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:25:18 by btan              #+#    #+#             */
/*   Updated: 2023/09/10 17:48:48 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	while (n-- > 0)
		((unsigned char *) s)[n] = c;
	return (s);
}
/*
#include <string.h>
#include <stdio.h>
int     main()
{
	char str[12] = "Hello World";
	
	printf("%s\n", (char *) memset(str, 'a', 7));
	printf("%s\n", (char *) ft_memset(str, 'a', 7));
}*/
