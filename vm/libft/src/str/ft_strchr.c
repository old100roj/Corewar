/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:34:17 by akasamar          #+#    #+#             */
/*   Updated: 2017/10/30 15:34:18 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	PROTECT(s);
	while (*s)
	{
		if (*s == c)
			return (char *)(s);
		s++;
	}
	if (*s == c)
		return (char *)(s);
	return (NULL);
}
