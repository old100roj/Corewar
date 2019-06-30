/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_count_occur.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:18:20 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/04 16:18:25 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str.h"

int	ft_str_count_occur(const char *str, char c)
{
	int count;
	int i;

	if (str == NULL)
		return (0);
	count = 0;
	i = 0;
	while (str[i])
	{
		count += str[i] == c;
		i++;
	}
	count += str[i] == c;
	return (count);
}
