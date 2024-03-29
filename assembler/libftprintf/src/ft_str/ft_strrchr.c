/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:38:39 by iganich           #+#    #+#             */
/*   Updated: 2017/11/06 17:38:41 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = 0;
	while (*s)
	{
		s++;
		len++;
	}
	if (*s == (char)c)
		return ((char *)s);
	while (len >= 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		len--;
		s--;
	}
	return (0);
}
