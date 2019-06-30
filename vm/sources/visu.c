/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 13:41:38 by iganich           #+#    #+#             */
/*   Updated: 2019/03/28 13:41:40 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"
#include "libft.h"

WINDOW *g_win;
uint8_t g_colors[MEM_SIZE];

void	visu_init_pairs(void)
{
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_YELLOW);
}

void	visu_change_code(unsigned int position, unsigned char c, int player_num)
{
	int y;
	int x;

	position++;
	y = position / FIELD_WIDTH + 1;
	x = ((position % FIELD_WIDTH) - 1) * 3 + 2;
	wattron(g_win, COLOR_PAIR(player_num));
	mvwprintw(g_win, y, x, "%.2x", c);
	if (position < MEM_SIZE)
		g_colors[position - 1] = player_num;
	wrefresh(g_win);
	wattroff(g_win, COLOR_PAIR(player_num));
}

void	visu_init_arena(size_t length)
{
	size_t			i;
	unsigned char	*tmp;

	i = 0;
	visu_init_pairs();
	tmp = ft_memalloc(MEM_SIZE);
	ft_memcpy(g_colors, tmp, MEM_SIZE);
	ft_memdel((void **)&tmp);
	while (i < length)
	{
		visu_change_code(i, 0, 0);
		i++;
	}
}

void	visu_place_player(unsigned int start, unsigned char *code,
			size_t length, int player_num)
{
	unsigned int i;

	i = 0;
	while (i < length)
	{
		visu_change_code(start + i, code[i], player_num);
		i++;
	}
}

void	change_carriage(unsigned int position, unsigned char c, bool erase)
{
	int		y;
	int		x;
	uint8_t	player_num;

	position++;
	y = position / FIELD_WIDTH + 1;
	x = ((position % FIELD_WIDTH) - 1) * 3 + 2;
	player_num = g_colors[position - 1];
	if (!erase)
		wattron(g_win, COLOR_PAIR(player_num + 5));
	else
		wattron(g_win, COLOR_PAIR(player_num));
	mvwprintw(g_win, y, x, "%.2x", c);
	wrefresh(g_win);
	if (!erase)
		wattroff(g_win, COLOR_PAIR(player_num + 5));
	else
		wattroff(g_win, COLOR_PAIR(player_num));
}
