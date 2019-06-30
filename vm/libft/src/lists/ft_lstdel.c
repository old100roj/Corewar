/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:37:37 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/14 14:37:41 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	if (!(alst && *alst && *del))
		return ;
	while (*alst)
	{
		tmp = (*alst)->next;
		ft_lstdelone(&(*alst), del);
		*alst = NULL;
		*alst = tmp;
	}
}
