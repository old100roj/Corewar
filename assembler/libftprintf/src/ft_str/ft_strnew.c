/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:45:59 by iganich           #+#    #+#             */
/*   Updated: 2017/11/07 19:46:00 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	i;

	res = (char *)malloc(size + 1);
	if (res)
	{
		i = 0;
		while (i <= size)
		{
			res[i] = '\0';
			i++;
		}
		return (res);
	}
	return (NULL);
}
