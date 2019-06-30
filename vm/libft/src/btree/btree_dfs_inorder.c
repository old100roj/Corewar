/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_dfs_inorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:06:25 by akasamar          #+#    #+#             */
/*   Updated: 2019/02/26 20:06:27 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_dfs_inorder(t_btree *root, void (*applyf)(void *))
{
	if (root == NULL || !*applyf)
		return ;
	btree_dfs_inorder(root->left, applyf);
	applyf(root->item);
	btree_dfs_inorder(root->right, applyf);
}
