/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:47:19 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:47:20 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

t_carriage	*new_carriage(int id, int pc)
{
	t_carriage *new_process;

	new_process = (t_carriage *)ft_memalloc(sizeof(t_carriage));
	if (new_process == NULL)
	{
		throw_error(ALLOC_ERR, NULL);
		return (NULL);
	}
	new_process->next = NULL;
	new_process->carry = false;
	new_process->cycles_left = -1;
	new_process->last_live_cycle = -1;
	new_process->pc = pc;
	new_process->registry[0] = -id;
	new_process->player_id = id;
	return (new_process);
}

void		add_carriage_to_lst(t_carriage **lst, t_carriage *proc, t_env *vm)
{
	if (!lst || !proc)
		return ;
	if (!*lst)
		*lst = proc;
	else
	{
		proc->next = *lst;
		*lst = proc;
	}
	vm->cursors++;
}

void		copy_carriage(t_env *vm, t_carriage *pointer, int addr)
{
	t_carriage *copy;

	copy = (t_carriage *)ft_memalloc(sizeof(t_carriage));
	if (copy == NULL)
	{
		throw_error(ALLOC_ERR, NULL);
		return ;
	}
	ft_memcpy(copy->registry, pointer->registry, (size_t)REG_NUMBER *
			sizeof(int32_t));
	copy->carry = pointer->carry;
	copy->last_live_cycle = pointer->last_live_cycle;
	copy->pc = mod_addr((uint32_t)(addr % MEM_SIZE));
	copy->step = 0;
	copy->cycles_left = 0;
	copy->player_id = pointer->player_id;
	add_carriage_to_lst(&vm->pointer, copy, vm);
}

void		init_carriages(t_env *vm)
{
	unsigned int	i;
	int				pc;

	vm->pointer = NULL;
	i = 1;
	pc = 0;
	while (i <= vm->players_num)
	{
		add_carriage_to_lst(&vm->pointer, new_carriage(PLAYER[IDX(i)]->id, pc),
			vm);
		pc += MEM_SIZE / vm->players_num;
		i++;
	}
}
