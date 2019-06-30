/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_exec_ops.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:20:58 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:20:59 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"
#include "visu.h"

void	set_carriage_init_ops(t_env *vm, t_carriage *pointer)
{
	while (pointer)
	{
		read_new_op(vm, pointer);
		pointer = pointer->next;
	}
}

void	read_new_op(t_env *vm, t_carriage *pointer)
{
	int op_code;

	op_code = ARENA[PC % MEM_SIZE];
	if (op_code >= 1 && op_code <= 16)
		OP = &g_op_tab[IDX(op_code)];
	pointer->cycles_left = OP ? OP->cycles_to_exec : 0;
}

void	execute_command(t_env *vm, t_carriage *pointer)
{
	STEP = OP_SIZE;
	if (OP)
	{
		OP->f_ptr(vm, pointer);
	}
	if (vm->flags.visual)
		change_carriage(pointer->pc, vm->arena[pointer->pc], true);
	PC = mod_addr(STEP + PC);
}

void	exec_carriage_ops(t_env *vm, t_carriage *pointer)
{
	vm->cycle++;
	vm->cycles_after_check++;
	while (pointer)
	{
		if (pointer->cycles_left == 0)
		{
			read_new_op(vm, pointer);
			if (vm->flags.visual)
				change_carriage(pointer->pc, vm->arena[pointer->pc], false);
		}
		if (pointer->cycles_left > 0)
			pointer->cycles_left--;
		if (pointer->cycles_left == 0)
		{
			execute_command(vm, pointer);
			reset_carriage(pointer);
		}
		pointer = pointer->next;
	}
}
