/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:20:01 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:20:02 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"
#include "visu.h"

bool	need_check(t_env *vm)
{
	return (vm->cycles_to_die <= 0 ||
		vm->cycles_to_die == vm->cycles_after_check);
}

void	start_game_cycle(t_env *vm)
{
	bool one_alive;

	one_alive = true;
	set_carriage_init_ops(vm, vm->pointer);
	vm->last_alive = vm->pointer->registry[0];
	vm->cycles_after_check = 0;
	while (one_alive)
	{
		if (vm->flags.visual)
			visu_check_pause();
		if (vm->cycle == vm->flags.dump)
			print_dump(vm);
		exec_carriage_ops(vm, vm->pointer);
		if (need_check(vm))
			one_alive = check_alive(vm);
	}
	if (vm->flags.visual)
		getchar();
}
