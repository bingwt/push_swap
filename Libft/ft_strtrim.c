/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 13:52:23 by btan              #+#    #+#             */
/*   Updated: 2023/09/16 18:11:22 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;

	begin = 0;
	end = ft_strlen(s1);
	if (!s1 && !set)
		return (NULL);
	while (ft_strchr(set, s1[begin]))
		begin++;
	while (ft_strrchr(set, s1[end]))
		end--;
	return (ft_substr(s1, begin, (end - begin) + 1));
}
//
//#include <stdio.h>
//int	main()
//{
//	char	s1[] = "  hello  ";
//	//char s1[] = "lorem \n ipsum \t dolor \n sit \t amet"
//	char	*set = " ";
//	//ft_strchr(set, s1[0]);
//	printf("%s\n", ft_strtrim(s1, set));
//	printf("%zu\n", ft_strlen(ft_strtrim(s1, set)));
//	printf("%zu\n", ft_strlen(s1));
//}
