/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:42:23 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:42:25 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	op_ld(t_env *vm, t_carriage *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	if (is_registry_id(ARG[1]))
	{
		REG[IDX(ARG[1])] = ARG[0];
		CARRY = REG[IDX(ARG[1])] == 0;
	}
}
