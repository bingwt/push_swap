/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:39:25 by btan              #+#    #+#             */
/*   Updated: 2023/09/16 17:22:02 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;	

	if (!dest && !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *) dest)[i] = ((unsigned char *) src)[i];
		i++;
	}
	return (dest);
}
/*{
	while (n-- > 0)
		*((unsigned char *) dest++) = *((unsigned char *) src++);
	return (dest);
}
#include <stdio.h>
#include <string.h>

int main()
{
	void *mem;	
	//char str1[] = "abcdefghijklmnopqrstuvwxyz";
			char str2[] = "zyxwvutsrqponmlkjihgfedcba";
if (!(mem = malloc(sizeof(*mem) * 30)))
			return (0);
	memset(mem, 'j', 30);
				//puts("str1 before memcpy ");
					//puts(str1);

						ft_memcpy(mem, str2, 26);

							puts("\nstr1 after memcpy ");
								puts(mem);

									return 0;
}
#include <stdio.h>
#include <string.h>
int main()
{
	    char str[100] = "Learningisfun";
	        char *first, *second;
		    first = str;
		        second = str;
			    printf("Original string :%s\n ", str);
			          
				     ft_memcpy(first + 8, first, 10);
				         printf("Faux : %s\n ", str);
				           
				                   memcpy(second + 8, first, 10);
				                       printf("Real : %s\n ", str);
				                         
				                             return 0;
				                             }*/
