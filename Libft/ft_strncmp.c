/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 00:28:32 by btan              #+#    #+#             */
/*   Updated: 2023/09/11 01:19:37 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && n--)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>

int main()
{
    char* first_str = "Geekz";
    char* second_str = "Geeks";
    
    printf("First String: %s\n", first_str);
    printf("Second String: %s\n", second_str);

    printf("Return value of strcmp(): %d\n",
           strncmp(first_str, second_str, 6));
    printf("Return value of strcmp(): %d\n",
           strncmp(first_str, second_str, 6));

    return 0;
}*/
