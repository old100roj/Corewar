/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:34:09 by akasamar          #+#    #+#             */
/*   Updated: 2017/11/20 15:34:12 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(char const *s, char c)
{
	int	words_num;

	words_num = 0;
	while (*s)
		if (*s == c)
			s++;
		else
		{
			words_num++;
			while (*s != c && *s)
				s++;
		}
	return (words_num);
}
