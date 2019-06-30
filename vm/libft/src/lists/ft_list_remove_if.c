/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:04:45 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/06 15:04:46 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *list;
	t_list *parent;
	t_list *tmp;

	list = *begin_list;
	parent = NULL;
	while (list)
	{
		tmp = list;
		if ((*cmp)(data_ref, list->content) == 0)
		{
			if (parent != NULL)
				parent->next = list->next;
			else
				*begin_list = list->next;
			ft_lstdelone(&list, &ft_lst_del_content);
		}
		else
			parent = list;
		list = tmp->next;
	}
}
