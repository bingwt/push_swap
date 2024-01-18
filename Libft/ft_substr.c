/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 04:05:28 by btan              #+#    #+#             */
/*   Updated: 2023/09/16 16:57:31 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_calloc(1, 1));
	if (len > (ft_strlen(s) - start))
		len = ft_strlen(s) - start;
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
/*
 {
	char	*new;

	if (!s)
		return (NULL);
	if (start >= len)
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	new = (char *)malloc(len + 1);
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, len + 1);
	return (new);

}*/
/*
#include <stdio.h>

int	main(int ac, char **av)
{
	char	s1[] = "Hello! World!";

	if (ac == 2)
	printf("The original string is: %s.\n The substring is %s.", av[1],
			ft_substr(av[1], 2, 3));
}
*/
/*
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	if (!s)
		return (NULL);
	if (start >= len)
		return (ft_strdup(""));
	if (len >= ft_strlen(s))
		len = ft_strlen(s);
	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, len + 1);
	return (sub);
}
*/
/*
#include <stdio.h>
int	main(void)
{
	printf("%s", ft_substr("hola", 4294967295, 0));
	return (0);
}*/
