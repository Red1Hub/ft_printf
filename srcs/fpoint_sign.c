/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpoint_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:16:11 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 14:28:16 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*just_sign(char *result, int sign)
{
	char *minus;
	char *strtmp;

	strtmp = NULL;
	minus = ft_memalloc(2);
	if (sign)
		minus[0] = '-';
	else
		minus[0] = '+';
	s_strjoin(&minus, &result, &strtmp, 1);
	ft_memdel((void**)&result);
	return (strtmp);
}

char	*addpoint(char *str, int pos, int bolpoint, int sign)
{
	char	*strtmp;
	int		i;
	int		len;

	if (!bolpoint)
		return (just_sign(str, sign));
	i = 0;
	len = ft_strlen(str);
	strtmp = ft_memalloc(len + 3);
	strtmp[0] = '+';
	if (sign)
		strtmp[0] = '-';
	while (i < pos)
	{
		strtmp[i + 1] = str[i];
		i++;
	}
	strtmp[i + 1] = '.';
	while (i < len)
	{
		strtmp[i + 2] = str[i];
		i++;
	}
	ft_memdel((void**)&str);
	return (strtmp);
}
