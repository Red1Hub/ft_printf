/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_mantissa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:08:19 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 15:14:51 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	pmten_decmantissa(char **result, int i, char **strtmpp)
{
	int		tmp0;
	char	*strtmp2;

	if (i > 0)
	{
		tmp0 = ft_strlen(result[0]);
		tmp0 = i - tmp0;
		if (tmp0 > 0)
		{
			strtmp2 = ft_memalloc(tmp0 + 1);
			tmp0--;
			while (tmp0 >= 0)
			{
				strtmp2[tmp0] = '0';
				tmp0--;
			}
			s_strjoin(&strtmp2, result, result, 1);
		}
	}
	ft_memdel((void**)strtmpp);
}

void	decimal_mantissa(char **result, long double fl, char *zerostr)
{
	t_floaki	floaki;
	int			i;
	char		*strtmpp;
	char		*strtmp2;

	floaki.f = fl;
	i = 0;
	strtmpp = ft_memalloc(2);
	strtmpp[0] = '0';
	while (floaki.parts.mantisa > 0)
	{
		if (floaki.parts.mantisa & 0x4000000000000000)
		{
			if (result[0])
				ft_memdel((void**)result);
			strtmp2 = power("5", i++ + 1);
			result[0] = charsum(strtmpp, strtmp2);
			s_strjoin(result, &zerostr, &strtmpp, 404);
			free(strtmp2);
		}
		else if (i++ || 1)
			s_strjoin(&strtmpp, &zerostr, &strtmpp, 404);
		floaki.parts.mantisa = floaki.parts.mantisa << 1;
	}
	pmten_decmantissa(result, i, &strtmpp);
}
