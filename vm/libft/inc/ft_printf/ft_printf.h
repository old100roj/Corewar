/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akasamar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/15 16:15:38 by akasamar          #+#    #+#             */
/*   Updated: 2018/07/15 16:15:40 by akasamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"
# include <stdint.h>
# include <limits.h>
# include "colors.h"
# include <ft_printf_structs.h>

# define START_SPEC '%'

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

#endif
