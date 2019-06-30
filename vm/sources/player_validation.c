/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_validation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:12:17 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:12:18 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

bool	is_cor_file(char *filename)
{
	return (bool)(ft_strlen(filename) > ft_strlen(COR)
	&& ft_strequ(ft_strrchr(filename, '.'), COR));
}

bool	valid_header(t_file file)
{
	return (file_read_uint32(file) == COREWAR_EXEC_MAGIC);
}
