/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:29:51 by akasamar          #+#    #+#             */
/*   Updated: 2017/10/30 18:29:52 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	PROTECT(s && *f);
	PROTECT(ret = ft_strnew(ft_strlen(s)));
	i = 0;
	while (s[i])
	{
		ret[i] = (*f)((char)s[i]);
		i++;
	}
	return (ret);
}
