/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btan <btan@student.42singapore.sg>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 08:14:30 by btan              #+#    #+#             */
/*   Updated: 2024/01/17 13:33:58 by btan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	handle_error(char *vars, char *error)
{
	if (!ft_strncmp(error, "CMD_NOT_FOUND", 13))
	{
		ft_printf_fd(2, "command not found: %s\n", vars);
		return (127);
	}
	if (!ft_strncmp(error, "NO_FILE", 7))
		ft_putstr_fd("no such file or directory: ", 2);
	if (!ft_strncmp(error, "NO_PERMS", 8))
		ft_putstr_fd("permission denied: ", 2);
	if (!ft_strncmp(error, "INVALID_INPUT", 13))
		ft_putstr_fd("invalid input: ", 2);
	if (vars)
		ft_printf_fd(2, "%s\n", vars);
	exit(1);
}
