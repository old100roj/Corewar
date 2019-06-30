/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enqueue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:00:21 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/04 16:00:33 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "queue.h"

void	enqueue(t_queue *q, void *data)
{
	t_qnode *node;

	if (q == NULL)
		return ;
	node = new_qnode(data);
	if (ft_is_empty(q->rear))
	{
		q->front = node;
		q->rear = node;
	}
	else
	{
		q->rear->next = node;
		q->rear = node;
	}
	q->size++;
}
