/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:30:09 by iganich           #+#    #+#             */
/*   Updated: 2019/06/27 16:30:48 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	corewar_usage(void)
{
	ft_putstr("Usage : ./corewar [-dump nbr_cycles] [[-n number] \
champion.cor] [...]\n");
	ft_putstr("-dump nbr_cycles\t: Dumps memory after nbr_cycles cycles then \
exits\n");
	ft_putstr("-n number\t\t: Sets the number of the next player\n");
	ft_putstr("-v \t\t\t: Visual mode\n");
	exit(EXIT_SUCCESS);
}

void	introduce_contestants(t_env *vm)
{
	unsigned i;

	ft_printf("Introducing contestants...\n");
	i = 0;
	while (i < vm->players_num)
	{
		ft_printf("* Player %d, ", i + 1);
		ft_printf("\"%s\" ", PLAYER[i]->name);
		ft_printf("(\"%s\") !\n", PLAYER[i]->comment);
		i++;
	}
}

void	announce_winner(t_env *vm, int winner_id)
{
	ft_printf("Contestant %d, ", winner_id);
	ft_printf("\"%s\", has won !\n", PLAYER[IDX(winner_id)]->name);
}
