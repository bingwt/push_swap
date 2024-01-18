/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 17:46:50 by btan              #+#    #+#             */
/*   Updated: 2023/09/16 19:02:28 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char const c, char sep)
{
	if (c == sep || c == '\0')
		return (1);
	return (0);
}

static int	count_words(char const *str, char sep)
{
	int	words;

	words = 0;
	while (*(str++))
		if (is_sep(*str, sep) && !is_sep(*(str - 1), sep))
			words++;
	return (words);
}

static char	**allocation_failed(char **arr, int i)
{
	while (i--)
		free(arr[i]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char const	*begin;
	char		**arr;
	int			i;

	arr = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!s || !arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (!is_sep(*s, c))
		{
			begin = s;
			while (!is_sep(*s, c) && *s)
				s++;
			arr[i++] = ft_substr(begin, 0, s - begin);
			if (!arr[i - 1])
				return (allocation_failed(arr, i));
		}
		else
			s++;
	}
	arr[i] = NULL;
	return (arr);
}
