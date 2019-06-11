/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floak.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:06:55 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 15:32:41 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*floaki_ss_cases(int exponent, int precision, int fsign, int bolpoint)
{
	char	*result;
	int		tmp0;
	int		tmp1;

	if (exponent >= 0)
	{
		result = power("2", exponent);
		tmp0 = 0;
	}
	else if (exponent < 0)
	{
		result = power("5", -exponent);
		tmp0 = -exponent;
		tmp1 = -exponent - ft_strlen(result) + 1;
	}
	minimize_error(&result, precision, tmp0, tmp1);
	result = addpoint(result, ft_strlen(result) - precision, bolpoint, fsign);
	return (result);
}

char	*floaki_s_cases(int exponent, int precision, int fsign, int bolpoint)
{
	char	*zerostr;
	char	*result;
	int		tmp0;
	int		tmp1;

	tmp1 = 0;
	tmp0 = 0;
	zerostr = ft_memalloc(2);
	zerostr[0] = '0';
	if (exponent + 16383 == 0)
	{
		result = zerostr;
		minimize_error(&result, precision, 0, -1);
		result = addpoint(result, 1, bolpoint, fsign);
		return (result);
	}
	if (exponent == 16384)
		return (infinity(fsign));
	free(zerostr);
	return (floaki_ss_cases(exponent, precision, fsign, bolpoint));
}

char	*floakii(char **result, int exponent, int precision)
{
	char	*strtmp;
	int		tmp1;
	int		tmp0;

	tmp0 = ft_strlen(result[0]) - 1;
	tmp1 = 0;
	if (exponent >= 0)
		strtmp = charmultip(result[0], power("2", exponent));
	else if (exponent < 0)
	{
		strtmp = charmultip(result[0], power("5", -exponent));
		tmp0 += -exponent;
		tmp1 = -exponent - (ft_strlen(strtmp) - ft_strlen(result[0]));
	}
	if (result[0])
		free(result[0]);
	minimize_error(&strtmp, precision, tmp0, tmp1);
	return (strtmp);
}

char	*floaki(long double fl, int precision, int bolpoint, int e)
{
	char		*result;
	t_floaki	floaki;
	char		*strtmp;
	int			exponent;

	if (e)
		return (e_floaki(fl, precision, bolpoint));
	floaki.f = fl;
	exponent = floaki.parts.exponent - 16383;
	result = NULL;
	decimal_mantissa(&result, fl, "0");
	if (floaki.parts.mantisa)
	{
		if (exponent == 16384)
			return (nani());
		strtmp = ft_strjoin("1", result);
		free(result);
		result = strtmp;
		result = floakii(&result, exponent, precision);
		result = addpoint(result, ft_strlen(result) -
				precision, bolpoint, floaki.parts.sign);
		return (result);
	}
	return (floaki_s_cases(exponent, precision, floaki.parts.sign, bolpoint));
}
