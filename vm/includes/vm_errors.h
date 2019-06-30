/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_errors.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:45:31 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 16:45:31 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_VM_ERRORS_H
# define COREWAR_VM_VM_ERRORS_H

# define FILE_ERR "Can't read source file %s"

# define READ_ERR "Read error"
# define ALLOC_ERR "Memory allocation error"

# define PLAYER_NUM_ERR1 "Not enough players to proceed!"
# define PLAYER_NUM_ERR2 "Too many players, see MAX_PLAYERS in corewar_op.h!"
# define PLAYER_ERR1 "Error: File %s has an invalid header!"
# define PLAYER_ERR2 "The player is incomplete!"
# define PLAYER_ERR3 "Error: no null!"
# define PLAYER_ERR4 "Player %s has a different code size that from header!"
# define PLAYER_ERR5 "Code size is larger than CHAMP_MAX_SIZE!"

# define FLAG_ERR "Illegal option: %s!"
# define FLAG_ARG_ERR "Specify a valid argument for %s option!"
# define FLAG_N_ERR "Player number must be between 1 and total num of players!"
# define FLAG_DUMP_ERR "Number od cycles must be a strictly positive integer!"

#endif
