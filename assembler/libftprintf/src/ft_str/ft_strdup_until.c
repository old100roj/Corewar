/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_until.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 20:37:10 by iganich           #+#    #+#             */
/*   Updated: 2018/10/24 20:37:16 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_until(char *line, char c)
{
	char	*res;
	int		len;

	if (!line)
		return (NULL);
	len = 0;
	while (line[len] != c && line[len])
		len++;
	res = ft_strnew(len);
	len = -1;
	while (line[++len] != c && line[len])
		res[len] = line[len];
	return (res);
}
