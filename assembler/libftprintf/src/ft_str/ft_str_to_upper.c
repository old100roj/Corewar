/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_upper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 16:19:16 by iganich           #+#    #+#             */
/*   Updated: 2018/09/17 16:19:17 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_to_upper(char *word)
{
	size_t	i;

	i = 0;
	while (i < ft_strlen(word))
	{
		word[i] = ft_toupper(word[i]);
		i++;
	}
	return (word);
}
