/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 15:26:02 by iganich           #+#    #+#             */
/*   Updated: 2019/03/26 15:26:03 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar_vm.h"

uint32_t	file_read_uint32(t_file file)
{
	int8_t	buffer[4];
	ssize_t	bytes_read;
	int		i;

	i = 3;
	while (i >= 0)
	{
		if ((bytes_read = read(file.fd, &buffer[i], 1)) != 1)
			throw_error(bytes_read == -1 ? READ_ERR :
				PLAYER_ERR2, file.name);
		i--;
	}
	return (*(uint32_t *)buffer);
}

void		push_back_player(t_champ **lst, t_champ *player)
{
	t_champ *temp;

	if (!lst || !player)
		return ;
	if (*lst == NULL)
		*lst = player;
	else
	{
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = player;
	}
}
