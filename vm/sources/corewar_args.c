/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:32:03 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:32:05 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

static void	find_flag(char ***argv, t_cw_flags *flags)
{
	int i;

	if (ft_strequ(**argv, "v"))
	{
		flags->visual = true;
		return ;
	}
	i = 0;
	while (i < MAX_OPTIONS)
	{
		if (ft_strequ(**argv, g_cw_flags[i].name))
			return (g_cw_flags[i].f_ptr(argv, flags));
		i++;
	}
	throw_error(FLAG_ERR, **argv);
}

void		parse_arguments(char **argv, t_env *vm)
{
	t_champ *lst;

	lst = NULL;
	while (*argv)
	{
		if (is_cor_file(*argv))
			parse_player(vm, *argv, &lst, &vm->flags.n);
		else if (**argv == '-' && ++(*argv))
			find_flag(&(argv), &vm->flags);
		else
			corewar_usage();
		argv++;
	}
	if (lst == NULL)
		throw_error(PLAYER_NUM_ERR1, NULL);
	set_players_ids(vm, lst);
}
