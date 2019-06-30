/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:47:29 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:47:30 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

bool	is_player_id(t_env *vm, int id)
{
	return (id <= -1 && id >= -(int)vm->players_num);
}

bool	is_registry_id(int id)
{
	return (id >= 1 && id <= REG_NUMBER);
}
