/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:44:02 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:44:03 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	op_sub(t_env *vm, t_carriage *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	if (is_registry_id(ARG[0]) && is_registry_id(ARG[1])
		&& is_registry_id(ARG[2]))
	{
		REG[IDX(ARG[2])] = REG[IDX(ARG[0])] - REG[IDX(ARG[1])];
		CARRY = REG[IDX(ARG[2])] == 0;
	}
}
