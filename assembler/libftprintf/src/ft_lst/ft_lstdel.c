/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:28:52 by iganich           #+#    #+#             */
/*   Updated: 2018/01/23 16:28:54 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;

	if (!(alst && del && *alst))
		return ;
	temp = *alst;
	while (temp)
	{
		*alst = temp->next;
		ft_lstdelone(&temp, del);
		temp = *alst;
	}
}
