/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:05:36 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/06 15:05:37 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_foreach(t_list *lst, void *(*f)(void *))
{
	t_list	*elem;

	if (!lst)
		return (NULL);
	if (!(elem = (t_list *)malloc(sizeof(*elem))))
		return (NULL);
	elem->content = (*f)(lst->content);
	elem->next = ft_lst_foreach(lst->next, f);
	return (elem);
}

void	ft_lst_foreach_subj(t_list *alst, void (*f)(void *))
{
	if (!alst || !*f)
		return ;
	while (alst)
	{
		f(alst->content);
		alst = alst->next;
	}
}
