/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:42:42 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:42:43 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	op_st(t_env *vm, t_carriage *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, true);
	if (is_registry_id(ARG[0]))
	{
		if (ARG_TYPE[1] == T_REG && is_registry_id(ARG[1]))
			REG[IDX(ARG[1])] = REG[IDX(ARG[0])];
		else if (ARG_TYPE[1] == IND_CODE)
		{
			ADDR = ARG[1] % IDX_MOD;
			write_to_arena(vm, pointer, REG[IDX(ARG[0])]);
		}
	}
}
