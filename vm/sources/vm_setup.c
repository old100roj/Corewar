/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:11:39 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:11:40 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

t_env	*init_vm(void)
{
	t_env *vm;

	vm = (t_env *)ft_memalloc(sizeof(t_env));
	vm->flags.dump = -1;
	vm->flags.n = -1;
	vm->flags.visual = false;
	vm->players_num = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->checks_count = 0;
	vm->lives_in_period = 0;
	vm->cursors = 0;
	return (vm);
}

void	set_defined_ids(t_env *vm, t_champ *lst)
{
	while (lst)
	{
		if (lst->id != -1)
		{
			if ((unsigned)lst->id > vm->players_num || PLAYER[lst->id - 1] != 0)
				throw_error(FLAG_N_ERR, NULL);
			else
				PLAYER[IDX(lst->id)] = lst;
		}
		lst = lst->next;
	}
}

void	set_players_ids(t_env *vm, t_champ *lst)
{
	unsigned int i;

	set_defined_ids(vm, lst);
	i = 0;
	while (lst)
	{
		if (lst->id == -1)
		{
			while (PLAYER[i] != 0 && i < vm->players_num)
				i++;
			PLAYER[i] = lst;
			PLAYER[i]->id = i + 1;
		}
		lst = lst->next;
	}
}
