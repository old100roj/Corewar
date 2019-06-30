/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:49:42 by iganich           #+#    #+#             */
/*   Updated: 2019/03/28 13:49:43 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	visu_check_pause(void)
{
	if (getch() == ' ')
		while (getch() != ' ')
			;
}

void	init_visu(void)
{
	initscr();
	noecho();
	timeout(0);
	cbreak();
	curs_set(0);
	start_color();
	refresh();
	g_win = newwin(MEM_SIZE / FIELD_WIDTH + 2, FIELD_WIDTH * 3, 0, 0);
	wborder(g_win, '*', '*', '*', '*', '*', '*', '*', '*');
	wrefresh(g_win);
	visu_init_arena(MEM_SIZE);
}

void	visu_delay(char temp)
{
	if (temp == ' ')
		while ((temp = getch()) != ' ')
			;
}
