/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:22:30 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/04 16:22:31 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;

	PROTECT(src);
	PROTECT(dest = ft_strnew(n));
	return (ft_strncpy(dest, src, n));
}
