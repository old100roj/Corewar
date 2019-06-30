/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:42:48 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:42:49 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	op_sti(t_env *vm, t_carriage *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	if (ARG_TYPE[1] == T_REG)
	{
		if (!is_registry_id(ARG[1]))
			return ;
		ARG[1] = REG[IDX(ARG[1])];
	}
	if (ARG_TYPE[2] == T_REG)
	{
		if (!is_registry_id(ARG[2]))
			return ;
		ARG[2] = REG[IDX(ARG[2])];
	}
	if (is_registry_id(ARG[0]))
	{
		ADDR = (ARG[1] + ARG[2]) % IDX_MOD;
		write_to_arena(vm, pointer, REG[IDX(ARG[0])]);
	}
}
