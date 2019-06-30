/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_dfs_postorder.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:06:34 by akasamar          #+#    #+#             */
/*   Updated: 2019/02/26 20:06:35 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_dfs_postorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || !*applyf)
		return ;
	btree_dfs_postorder(root->right, applyf);
	btree_dfs_postorder(root->left, applyf);
	applyf(root->item);
}
