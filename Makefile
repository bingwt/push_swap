# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 19:17:02 by btan              #+#    #+#              #
#    Updated: 2024/01/18 20:08:54 by btan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


test:
	cc test_array.c -ILibft libft.a -g
