/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:43:38 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:43:39 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	op_live(t_env *vm, t_carriage *pointer)
{
	vm->lives_in_period++;
	pointer->last_live_cycle = vm->cycle;
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	if (is_player_id(vm, ARG[0]))
	{
		PLAYER[IDX(FT_ABS(ARG[0]))]->last_live_cycle = vm->cycle;
		PLAYER[IDX(FT_ABS(ARG[0]))]->lives++;
		vm->last_alive = ARG[0];
	}
}
