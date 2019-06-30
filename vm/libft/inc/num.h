/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:08:07 by akasamar          #+#    #+#             */
/*   Updated: 2019/03/04 16:10:08 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_H
# define NUM_H

# include "libft.h"

# define EXT_SP(x) ((SPACE(x)) || (x) == '\r' || (x) == '\f' ||	(x) == '\v')
# define FT_LCASE(x)	((x) >= 97 && (x) <= 122)

size_t	ft_numlen(int n);
bool	ft_in_base(char c, int base);

int		ft_atoi_base(const char *str, int base);
char	*ft_itoa_base(int n, int base);
char	*ft_itoa(int n);
long	ft_strtol(const char *str, char **endptr, int base);

#endif
