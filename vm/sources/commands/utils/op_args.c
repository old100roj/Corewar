/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:09:05 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:09:13 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

int32_t	get_reg_index(t_env *vm, t_carriage *pointer)
{
	return (ARENA[mod_addr((uint32_t)(PC + STEP))]);
}

int32_t	get_dir_value(t_env *vm, t_carriage *pointer)
{
	return (read_from_arena(ARENA, PC + STEP + ADDR,
		DIR_SIZE >> OP->t_dir_size_diff));
}

int32_t	get_ind_value(t_env *vm, t_carriage *pointer)
{
	int32_t addr;

	addr = read_from_arena(ARENA, PC + STEP, IND_SIZE);
	ADDR = OP->idx_mod ? addr % IDX_MOD : addr;
	return (read_from_arena(ARENA, PC + ADDR, DIR_SIZE >> OP->t_dir_size_diff));
}

void	get_args(t_env *vm, t_carriage *pointer, bool return_ind_addr)
{
	int n;

	n = 0;
	while (n < pointer->op->arg_num)
	{
		if (pointer->arg_type[n] == REG_CODE)
		{
			ARG[n] = get_reg_index(vm, pointer);
			STEP += REG_IDX_SIZE;
		}
		else if (pointer->arg_type[n] == DIR_CODE)
		{
			ARG[n] = get_dir_value(vm, pointer);
			STEP += DIR_SIZE >> OP->t_dir_size_diff;
		}
		else if (pointer->arg_type[n] == IND_CODE)
		{
			ARG[n] = return_ind_addr ? read_from_arena(ARENA, PC + STEP,
				IND_SIZE) : get_ind_value(vm, pointer);
			STEP += IND_SIZE;
		}
		n++;
	}
}
