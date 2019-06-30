/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:41:11 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:41:12 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	op_aff(t_env *vm, t_carriage *pointer)
{
	if (get_arg_types(vm, pointer) == false)
		return ;
	get_args(vm, pointer, false);
	if (is_registry_id(ARG[0]))
		ft_printf("Aff: %c\n", (char)REG[IDX(ARG[0])]);
}
