/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:45:45 by iganich           #+#    #+#             */
/*   Updated: 2017/11/07 19:45:47 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*res;
	unsigned int	i;

	res = (unsigned char *)malloc(size);
	if (res)
	{
		i = 0;
		while (i < size)
		{
			res[i] = '\0';
			i++;
		}
		return (res);
	}
	return (NULL);
}
