/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:31:16 by akasamar          #+#    #+#             */
/*   Updated: 2017/10/30 18:31:20 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	PROTECT(s && *f);
	PROTECT(ret = ft_strnew(ft_strlen(s)));
	i = 0;
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	return (ret);
}
