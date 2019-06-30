/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_io.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:19:14 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 16:19:15 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"
#include "visu.h"

void		place_players_on_arena(t_env *vm, t_carriage *pointer)
{
	int				pos;
	unsigned int	i;

	pos = 0;
	i = 0;
	while (i < vm->players_num)
	{
		ft_memcpy(&vm->arena[pos], PLAYER[i]->code, PLAYER[i]->code_size);
		if (vm->flags.visual)
			visu_place_player(pos, PLAYER[i]->code, PLAYER[i]->code_size,
				i + 1);
		pos += MEM_SIZE / vm->players_num;
		pointer = pointer->next;
		i++;
	}
}

uint8_t		*convert_int32_to_int8(uint32_t value)
{
	uint8_t		*res;
	int			i;

	i = 3;
	res = (uint8_t *)ft_memalloc(4 * sizeof(uint8_t));
	if (!res)
	{
		throw_error(ALLOC_ERR, NULL);
		return (NULL);
	}
	while (i >= 0)
	{
		res[i] = (uint8_t)(value % 256);
		value /= 256;
		i--;
	}
	return (res);
}

void		write_to_arena(t_env *vm, t_carriage *pointer, int32_t value)
{
	uint8_t		*bytes;
	uint32_t	addr;
	int			i;

	bytes = convert_int32_to_int8((uint32_t)value);
	i = 0;
	while (i < REG_SIZE)
	{
		addr = mod_addr((uint32_t)(PC + ADDR + i));
		if (vm->flags.visual)
			visu_change_code(addr, bytes[i], pointer->player_id);
		ARENA[addr] = bytes[i];
		i++;
	}
	ft_memdel((void **)&bytes);
}

uint32_t	mod_addr(uint32_t addr)
{
	return (addr % MEM_SIZE);
}

int32_t		read_from_arena(const uint8_t *src, int addr, int n)
{
	uint8_t	*buffer;
	int32_t	res;
	int		i;

	addr = mod_addr((uint32_t)addr);
	if (!(buffer = (uint8_t *)ft_memalloc(sizeof(uint8_t) * n + 1)))
	{
		throw_error(ALLOC_ERR, NULL);
		return (0);
	}
	i = n;
	while (--i >= 0)
	{
		buffer[i] = src[addr % MEM_SIZE];
		addr++;
	}
	res = 0;
	if (n == 2)
		res = *(int16_t *)buffer;
	else if (n == 1)
		res = *(int8_t *)buffer;
	else if (n == 4)
		res = *(int32_t *)buffer;
	ft_memdel((void **)&buffer);
	return (res);
}
