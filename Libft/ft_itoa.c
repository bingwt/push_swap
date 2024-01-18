/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:14:25 by btan              #+#    #+#             */
/*   Updated: 2023/09/16 18:12:40 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nbr;

	len = intlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	nbr = n;
	if (nbr < 0)
		nbr = -nbr;
	str[len] = '\0';
	if (!nbr)
		str[0] = '0';
	while (len--)
	{
		str[len] = '0' + nbr % 10;
		nbr /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
//#include <stdio.h>
//int	main(int argc, char **argv)
//{
//	printf("%d\n", intlen(ft_atoi(argv[1])));
//	printf("%s\n", ft_itoa(ft_atoi(argv[1])));
//	printf("%zu	\n", ft_strlen(ft_itoa(ft_atoi(argv[1]))));
//}
