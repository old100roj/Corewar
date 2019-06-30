/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:31:19 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:31:20 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	print_arena(t_env *vm)
{
	int		pc;

	pc = 0;
	if (!vm)
		return ;
	while (pc < MEM_SIZE)
	{
		if (pc % 32 == 0)
		{
			if (pc > 0)
				ft_printf("\n");
			ft_printf("%#.4p : ", pc);
		}
		ft_printf("%02x ", ARENA[pc]);
		pc++;
	}
	ft_putchar('\n');
}

void	print_dump(t_env *vm)
{
	print_arena(vm);
	memory_free(vm);
	exit(EXIT_SUCCESS);
}
