/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:32:09 by akasamar          #+#    #+#             */
/*   Updated: 2017/10/30 18:32:11 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	index;

	index = 0;
	PROTECT(s);
	PROTECT(ret = ft_strnew(len));
	len += start;
	while (start != len)
	{
		ret[index] = s[start];
		start++;
		index++;
	}
	return (ret);
}
