/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 17:07:16 by iganich           #+#    #+#             */
/*   Updated: 2017/11/06 17:07:18 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)src;
	str = (unsigned char*)dst;
	while (i < n)
	{
		str[i] = temp[i];
		i++;
	}
	dst = (void *)str;
	return (dst);
}
