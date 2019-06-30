/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:24:26 by akasamar          #+#    #+#             */
/*   Updated: 2018/10/07 15:24:27 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	*stack_pop(t_stack **root_ptr)
{
	t_stack	*temp;
	void	*popped;

	if (!root_ptr || !*root_ptr)
		return (NULL);
	popped = (*root_ptr)->data;
	temp = *root_ptr;
	*root_ptr = (*root_ptr)->next;
	free(temp);
	return (popped);
}
