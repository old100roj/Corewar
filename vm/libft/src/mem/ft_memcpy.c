/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcpy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:14:41 by akasamar          #+#    #+#             */
/*   Updated: 2017/10/30 17:14:43 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	if (!dst && !src)
		return (NULL);
	dptr = (unsigned char *)dst;
	sptr = (const unsigned char *)src;
	while (n--)
		*dptr++ = *sptr++;
	return (dst);
}
