/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:43:04 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:43:05 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"
#include "visu.h"

void	op_zjmp(t_env *vm, t_carriage *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	if (CARRY)
	{
		if (vm->flags.visual)
			change_carriage(pointer->pc, vm->arena[pointer->pc], true);
		PC = mod_addr(PC + ARG[0] % IDX_MOD);
		STEP = 0;
	}
}
