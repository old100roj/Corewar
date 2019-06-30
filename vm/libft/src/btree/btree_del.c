/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:06:10 by akasamar          #+#    #+#             */
/*   Updated: 2019/02/26 20:06:12 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_del(t_btree **root, void (*del_content)(void *, size_t))
{
	if (!root || !*root || !*del_content)
		return ;
	btree_del(&(*root)->left, del_content);
	btree_del(&(*root)->right, del_content);
	btree_delone(root, del_content);
}
