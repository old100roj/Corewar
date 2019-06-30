/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:42:38 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:42:38 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	op_lldi(t_env *vm, t_carriage *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	if (ARG_TYPE[0] == T_REG)
	{
		if (!is_registry_id(ARG[0]))
			return ;
		ARG[0] = REG[IDX(ARG[0])];
	}
	if (ARG_TYPE[1] == T_REG)
	{
		if (!is_registry_id(ARG[1]))
			return ;
		ARG[1] = REG[IDX(ARG[1])];
	}
	if (is_registry_id(ARG[2]))
	{
		ADDR = (ARG[0] + ARG[1]);
		REG[IDX(ARG[2])] = read_from_arena(ARENA, PC + ADDR, DIR_SIZE);
	}
}
