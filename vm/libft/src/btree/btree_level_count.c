/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 20:07:29 by akasamar          #+#    #+#             */
/*   Updated: 2019/02/26 20:07:30 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + FT_MAX(btree_level_count(root->left),
						btree_level_count(root->right)));
}
