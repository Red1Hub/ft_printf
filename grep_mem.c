/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prnt_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 11:29:16 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/10 14:50:13 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*grep_mem(long double fl)
{
	t_floaki	floaki;
	int			i;
	char		*result;

	floaki.f = fl;
	i = 0;
	result = (char*)malloc(sizeof(char) * 84);
	result[83] = '\0';
	result[i++] = '+';
	result[i++] = (floaki.parts.sign) ? '1' : '0';
	result[i++] = ' ';
	while (i < 17)
	{
		result[i++] = (floaki.parts.exponent & 16384) ? '1' : '0';
		floaki.parts.exponent = floaki.parts.exponent << 1;
	}
	result[i++] = ' ';
	result[i++] = (floaki.parts.intgprt) ? '1' : '0';
	result[i++] = ' ';
	while (i < 83)
	{
		result[i++] = (floaki.parts.mantisa & 0x4000000000000000) ? '1' : '0';
		floaki.parts.mantisa = floaki.parts.mantisa << 1;
	}
	return (result);
}
