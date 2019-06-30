/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:24:14 by akasamar          #+#    #+#             */
/*   Updated: 2018/10/07 15:24:15 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

size_t	stack_size(t_stack *stack)
{
	size_t stack_size;

	stack_size = 0;
	while (!ft_is_empty(stack))
	{
		stack_size++;
		stack = stack->next;
	}
	return (stack_size);
}
