/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:32:44 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:32:45 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"
#include "visu.h"

t_flag_disp g_cw_flags[] =
{
	{"n", &parse_champ_id},
	{"dump", &parse_dump_cycles},
};

void	play_corewar(t_env *vm)
{
	if (vm->flags.visual)
		init_visu();
	place_players_on_arena(vm, vm->pointer);
	if (vm->flags.visual)
		visu_delay(' ');
	if (!vm->flags.visual)
		introduce_contestants(vm);
	start_game_cycle(vm);
	if (vm->flags.visual)
	{
		getch();
		curs_set(1);
		refresh();
		endwin();
	}
	announce_winner(vm, FT_ABS(vm->last_alive));
}

int		main(int argc, char **argv)
{
	t_env *vm;

	if (argc < 2)
		corewar_usage();
	else
	{
		vm = init_vm();
		parse_arguments(++argv, vm);
		init_carriages(vm);
		play_corewar(vm);
		memory_free(vm);
	}
	return (0);
}
