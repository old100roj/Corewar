/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:07:48 by akasamar          #+#    #+#             */
/*   Updated: 2019/02/26 20:07:49 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmp)(void *, void *))
{
	t_btree *found;

	if (!root || !data_ref || !*cmp)
		return (NULL);
	found = btree_search_item(root->left, data_ref, cmp);
	if (!found && cmp(root->item, data_ref) == 0)
		found = root;
	if (!found)
		found = btree_search_item(root->right, data_ref, cmp);
	return (found);
}
