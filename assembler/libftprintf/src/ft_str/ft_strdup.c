/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:19:03 by iganich           #+#    #+#             */
/*   Updated: 2017/11/06 17:19:05 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*res;
	size_t	i;

	length = 0;
	if (!s1)
		return (NULL);
	while (s1[length])
		length++;
	res = (char *)malloc(length + 1);
	if (res)
	{
		i = 0;
		while (i < length)
		{
			res[i] = s1[i];
			i++;
		}
		res[i] = '\0';
	}
	return (res);
}
