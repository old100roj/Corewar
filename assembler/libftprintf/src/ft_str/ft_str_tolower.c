/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_tolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 19:07:19 by iganich           #+#    #+#             */
/*   Updated: 2018/10/17 19:07:19 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(char *word)
{
	size_t i;

	i = 0;
	while (i < ft_strlen(word))
	{
		word[i] = ft_tolower(word[i]);
		i++;
	}
	return (word);
}
