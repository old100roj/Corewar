/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:26:47 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:26:48 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

void	parse_champ_id(char ***argv, t_cw_flags *flags)
{
	if (ft_is_empty(*(*argv + 1))
		|| ft_is_empty(*(*argv + 2))
		|| !is_cor_file(*(*argv + 2)))
		throw_error(FLAG_ARG_ERR, **argv);
	(*argv)++;
	if (!ft_is_numeric(**argv))
		throw_error(FLAG_N_ERR, NULL);
	flags->n = ft_atoi(**argv);
	if (flags->n < 1 || flags->n > MAX_PLAYERS)
		throw_error(FLAG_N_ERR, NULL);
}

void	parse_dump_cycles(char ***argv, t_cw_flags *flags)
{
	if (ft_is_empty(*(*argv + 1)))
		throw_error(FLAG_ARG_ERR, **argv);
	(*argv)++;
	if (!ft_is_numeric(**argv))
		throw_error(FLAG_DUMP_ERR, **argv);
	flags->dump = ft_atoi(**argv);
	if (flags->dump < 0)
		throw_error(FLAG_DUMP_ERR, **argv);
}
