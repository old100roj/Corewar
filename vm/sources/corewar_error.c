/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:29:39 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:29:39 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"
#include <errno.h>

void	throw_error(char *fmt, char *filename)
{
	ft_dprintf(STDERR_FILENO, fmt, filename);
	ft_putendl_fd("", STDERR_FILENO);
	exit(EXIT_FAILURE);
}
