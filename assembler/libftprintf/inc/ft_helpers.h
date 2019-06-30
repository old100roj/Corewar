/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 13:28:15 by iganich           #+#    #+#             */
/*   Updated: 2018/08/17 13:28:18 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HELPERS_H
# define FT_HELPERS_H

# include <stdint.h>
# include <stdarg.h>
# include "printf_structs.h"

char	*ft_string_itoa_base(uintmax_t a, char c,
	int base, t_format_specifier *sp);
char	*ft_string_ftoa(long double a, char c, int base,
	t_format_specifier *sp);
void	ft_handle_flags(va_list ap, const char **s, t_format_specifier *sp);
int		ft_wide_char_len(unsigned int a);

#endif
