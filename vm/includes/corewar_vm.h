/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_vm.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 16:34:49 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 16:34:50 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_VM_H
# define COREWAR_VM_H

# include "libft.h"
# include "vm_errors.h"
# include "corewar_op.h"
# include <fcntl.h>
# define PLAYER (vm->players)
# define ARENA (vm->arena)
# define COR ".cor"
# define IDX(X) ((X) - 1)
# define PC (pointer->pc)
# define STEP (pointer->step)
# define ARG_TYPE (pointer->arg_type)
# define REG (pointer->registry)
# define ARG (pointer->args)
# define CARRY (pointer->carry)
# define OP (pointer->op)
# define ADDR (pointer->addr)

# define MAX_OPTIONS 2

/*
** uint8_t/OCTET	is unsigned char
** uint16_t			is unsigned short
** uint32_t			is unsigned int
*/

typedef struct	s_player
{
	int				id;
	char			*name;
	char			*comment;
	size_t			code_size;
	unsigned char	*code;
	int				last_live_cycle;
	unsigned int	lives;
	struct s_player	*next;
}				t_champ;

/*
** cycles left - delay before op execute
** arg_len - length of arguments due to it coding octet
** step - calculate operation step within its arguments coding octet etc
*/

typedef struct	s_carriage
{
	int32_t				registry[REG_NUMBER];
	int32_t				player_id;
	int32_t				pc;
	int32_t				step;
	int32_t				arg_len;
	int32_t				addr;
	int32_t				cycles_left;
	int32_t				last_live_cycle;
	bool				carry;
	t_op				*op;
	t_arg_type			arg_type[MAX_ARGS_NUMBER];
	int32_t				args[MAX_ARGS_NUMBER];
	struct s_carriage	*next;
}				t_carriage;

typedef struct	s_cw_flags
{
	int		n;
	int		dump;
	bool	visual;
}				t_cw_flags;
/*
** lives_num number of lives since last cycle_to_die
*/

typedef	struct	s_env
{
	t_cw_flags	flags;
	t_champ		*players[MAX_PLAYERS];
	uint8_t		arena[MEM_SIZE];
	uint32_t	players_num;
	int32_t		cycles_to_die;
	int32_t		checks_count;
	int32_t		cycles_after_check;
	int32_t		last_alive;
	int32_t		cursors;
	int32_t		cycle;
	size_t		lives_in_period;
	t_carriage	*pointer;
}				t_env;

typedef struct	s_file
{
	char	*name;
	int		fd;
}				t_file;

typedef struct	s_flags_disp
{
	char	*name;
	void	(*f_ptr)(char***, t_cw_flags*);
}				t_flag_disp;

extern t_flag_disp	g_cw_flags[];

/*
******************************* Parsing ***********************************
*/

void			parse_arguments(char **argv, t_env *vm);
void			parse_player(t_env *vm, char *filename, t_champ **lst, int *id);
void			parse_champ_id(char ***argv, t_cw_flags *flags);
void			parse_dump_cycles(char ***argv, t_cw_flags *flags);

/*
******************************* Validation *************************************
*/

bool			is_cor_file(char *filename);
bool			valid_header(t_file file);
bool			is_player_id(t_env *vm, int id);
bool			is_registry_id(int id);
void			corewar_usage();
void			play_corewar(t_env *vm);
void			memory_free(t_env *vm);
void			throw_error(char *fmt, char *filename);

/*
******************************* Utils ***********************************
*/

void			push_back_player(t_champ **lst, t_champ *player);
uint32_t		file_read_uint32(t_file file);
uint32_t		mod_addr(uint32_t addr);
void			print_dump(t_env *vm);

/*
******************************* VM ***********************************
*/

void			set_players_ids(t_env *vm, t_champ *lst);
t_env			*init_vm();

/*
******************************* Arena I/O ***********************************
*/

int32_t			read_from_arena(const uint8_t *src, int addr, int n);
void			write_to_arena(t_env *vm, t_carriage *pointer, int32_t value);
void			place_players_on_arena(t_env *vm, t_carriage *pointer);

/*
******************************* Operation arguments **************************
*/

bool			get_arg_types(t_env *vm, t_carriage *pointer);
void			get_args(t_env *vm, t_carriage *pointer, bool return_ind_addr);

/*
******************************* Carriage ***********************************
*/

void			init_carriages(t_env *vm);
void			add_carriage_to_lst(t_carriage **lst, t_carriage *proc,
	t_env *vm);
void			copy_carriage(t_env *vm, t_carriage *pointer, int addr);
void			set_carriage_init_ops(t_env *vm, t_carriage *pointer);

/*
******************************* Main Cycle ***********************************
*/

void			start_game_cycle(t_env *vm);
bool			check_alive(t_env *vm);
void			read_new_op(t_env *vm, t_carriage *pointer);
void			reset_carriage(t_carriage *pointer);
void			reset_player_lives(t_env *vm);

/*
******************************* Echo ******************************************
*/

void			introduce_contestants(t_env *vm);
void			announce_winner(t_env *vm, int winner);

/*
*************************** Operation execution *******************************
*/

void			exec_carriage_ops(t_env *vm, t_carriage *pointer);

#endif
