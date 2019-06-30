/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:42:09 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:42:10 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	op_fork(t_env *vm, t_carriage *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	copy_carriage(vm, pointer, PC + ARG[0] % IDX_MOD);
}
