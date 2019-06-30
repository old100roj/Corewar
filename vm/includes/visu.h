/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 14:32:27 by iganich           #+#    #+#             */
/*   Updated: 2019/03/28 14:32:27 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_H
# define VISU_H
# define FIELD_WIDTH 64

# include <ncurses.h>
# include "corewar_vm.h"

void		visu_init_arena(size_t length);
void		visu_place_player(unsigned int start, unsigned char *code,
					size_t length, int player_num);
void		visu_change_code(unsigned int position, unsigned char c,
					int player_num);
bool		is_carriage_at_address(t_carriage *head, uint32_t addr);
void		change_carriage(unsigned int position, unsigned char c, bool erase);
void		visu_check_pause(void);
void		init_visu(void);
void		visu_delay(char temp);

uint8_t	g_colors[MEM_SIZE];
extern WINDOW	*g_win;

#endif
