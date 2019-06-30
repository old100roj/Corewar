/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cycle_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:19:05 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:19:05 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	reset_carriage(t_carriage *pointer)
{
	OP = NULL;
	ADDR = 0;
	ft_bzero(ARG_TYPE, MAX_ARGS_NUMBER);
	ft_bzero(ARG, sizeof(ARG));
}

void	reset_player_lives(t_env *vm)
{
	unsigned int i;

	i = 0;
	while (i < vm->players_num)
	{
		vm->players[i]->lives = 0;
		i++;
	}
	vm->lives_in_period = 0;
}
