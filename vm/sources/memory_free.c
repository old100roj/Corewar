/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:16:07 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:16:08 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	free_players(t_env *vm)
{
	unsigned int		i;

	i = 0;
	while (i < vm->players_num)
	{
		PLAYER[i] = PLAYER[i];
		ft_strdel(&PLAYER[i]->name);
		ft_strdel(&PLAYER[i]->comment);
		ft_memdel((void **)&PLAYER[i]->code);
		ft_memdel((void **)&PLAYER[i]);
		i++;
	}
}

void	free_carriages(t_carriage *pointer)
{
	t_carriage *del;

	while (pointer)
	{
		del = pointer;
		pointer = pointer->next;
		ft_memdel((void **)&del);
	}
}

void	memory_free(t_env *vm)
{
	free_players(vm);
	free_carriages(vm->pointer);
	free(vm);
}
