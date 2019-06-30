/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 16:49:16 by iganich           #+#    #+#             */
/*   Updated: 2018/01/28 16:49:18 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int a)
{
	int res;

	if (a < 0)
		return (-1);
	res = 0;
	while (res * res <= a)
		res++;
	return (res - 1);
}