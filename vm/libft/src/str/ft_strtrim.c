/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:32:39 by akasamar          #+#    #+#             */
/*   Updated: 2017/10/30 18:32:40 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	size_t	begin;
	size_t	end;
	size_t	ret_len;

	PROTECT(s);
	end = ft_strlen(s);
	begin = 0;
	while (SPACE(s[begin]))
		begin++;
	while (SPACE(s[end - 1]))
		end--;
	ret_len = end - begin;
	s += begin;
	PROTECT(ret = ft_strnew(ret_len));
	ft_strncpy(ret, s, ret_len);
	return (ret);
}
