/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_argtypes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:47:23 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/26 16:47:24 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	decode_type_code(t_arg_type *args, int32_t codage_byte)
{
	args[0] = (t_arg_type)(codage_byte >> 6 & 3);
	args[1] = (t_arg_type)(codage_byte >> 4 & 3);
	args[2] = (t_arg_type)(codage_byte >> 2 & 3);
}

void	copy_arg_types(t_arg_type *args, t_arg_type *new_types)
{
	args[0] = new_types[0];
	args[1] = new_types[1];
	args[2] = new_types[2];
}

bool	valid_arg_types(const t_arg_type *curr_types, t_op *op)
{
	int i;

	i = 0;
	while (i < op->arg_num)
	{
		if ((curr_types[i] + (curr_types[i] == 3) & op->arg_type[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}

void	calc_arg_len(t_carriage *pointer)
{
	int i;

	i = 0;
	pointer->arg_len = 0;
	while (i < OP->arg_num)
	{
		if (ARG_TYPE[i] == REG_CODE)
			pointer->arg_len += REG_IDX_SIZE;
		else if (ARG_TYPE[i] == DIR_CODE)
			pointer->arg_len += DIR_SIZE >> OP->t_dir_size_diff;
		else if (ARG_TYPE[i] == IND_CODE)
			pointer->arg_len += IND_SIZE;
		i++;
	}
}

bool	get_arg_types(t_env *vm, t_carriage *pointer)
{
	if (OP->arg_codes)
	{
		decode_type_code(ARG_TYPE, ARENA[mod_addr((uint32_t)(PC + STEP))]);
		STEP++;
	}
	else
		copy_arg_types(ARG_TYPE, OP->arg_type);
	if (valid_arg_types(ARG_TYPE, OP) == false)
	{
		calc_arg_len(pointer);
		STEP += pointer->arg_len;
		return (false);
	}
	return (true);
}
