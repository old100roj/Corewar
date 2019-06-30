/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:22:25 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:22:26 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"
#include "visu.h"

bool	need_to_remove(t_env *vm, t_carriage *pointer)
{
	return (vm->cycles_to_die <= 0 ||
				vm->cycle - pointer->last_live_cycle >= vm->cycles_to_die);
}

bool	remove_dead_carriages(t_env *vm, t_carriage *temp)
{
	bool		one_alive;
	t_carriage	*prev;

	temp = vm->pointer;
	one_alive = false;
	prev = NULL;
	while (temp)
		if (need_to_remove(vm, temp))
		{
			(prev) ? (prev->next = temp->next) :
						(vm->pointer = vm->pointer->next);
			if (vm->flags.visual)
				change_carriage(temp->pc, vm->arena[temp->pc], true);
			ft_memdel((void **)&temp);
			vm->cursors--;
			(prev) ? (temp = prev->next) :
						(temp = vm->pointer);
		}
		else
		{
			prev = temp;
			one_alive = true;
			temp = temp->next;
		}
	return (one_alive);
}

bool	check_alive(t_env *vm)
{
	bool	one_alive;

	vm->checks_count++;
	one_alive = remove_dead_carriages(vm, vm->pointer);
	if (vm->checks_count == MAX_CHECKS || vm->lives_in_period >= NBR_LIVE)
	{
		vm->cycles_to_die -= CYCLE_DELTA;
		vm->checks_count = 0;
	}
	vm->cycles_after_check = 0;
	reset_player_lives(vm);
	return (one_alive);
}
