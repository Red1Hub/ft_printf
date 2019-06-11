/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_spec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:22:26 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 15:32:20 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	e_sci_fi(char **str, int a, int b)
{
	char *strtmp1;
	char *strtmp2;
	char *strtmp3;

	if (a >= 0)
	{
		strtmp1 = (a < 10) ? "e-0" : "e-";
		strtmp2 = ft_itoa(a);
		s_strjoin(&strtmp1, &strtmp2, &strtmp2, 404);
		s_strjoin(str, &strtmp2, str, 2);
		return ;
	}
	else if (b >= 0)
	{
		strtmp1 = (b < 10) ? "e+0" : "e+";
		strtmp2 = ft_itoa(b);
		s_strjoin(&strtmp1, &strtmp2, &strtmp2, 404);
		s_strjoin(str, &strtmp2, str, 2);
	}
}

char	*e_floaki_ss_cases(int exponent, int precision, int fsign, int bolpoint)
{
	char	*result;
	int		tmp0;
	int		tmp1;
	int		tmp2;

	if (exponent >= 0)
	{
		result = power("2", exponent);
		tmp0 = 0;
		tmp1 = -404;
		tmp2 = ft_strlen(result) - tmp0 - 1;
	}
	else if (exponent < 0)
	{
		result = power("5", -exponent);
		tmp0 = -exponent;
		tmp1 = -exponent - ft_strlen(result) + 1;
		tmp2 = -404;
	}
	minimize_error(&result, precision, ft_strlen(result) - 1, -1);
	e_sci_fi(&result, tmp1, tmp2);
	result = addpoint(result, 1, bolpoint, fsign);
	return (result);
}

char	*e_floaki_s_cases(int exponent, int precision, int fsign, int bolpoint)
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
		e_sci_fi(&result, -404, 0);
		result = addpoint(result, 1, bolpoint, fsign);
		return (result);
	}
	if (exponent == 16384)
		return (infinity(fsign));
	free(zerostr);
	return (e_floaki_ss_cases(exponent, precision, fsign, bolpoint));
}

char	*e_floakii(char **result, int exponent, int precision)
{
	char	*strtmp;
	int		tmp1;
	int		tmp0;
	int		tmp2;

	tmp0 = ft_strlen(result[0]) - 1;
	if (exponent >= 0)
	{
		strtmp = charmultip(result[0], power("2", exponent));
		tmp1 = -404;
		tmp2 = ft_strlen(strtmp) - tmp0 - 1;
	}
	else if (exponent < 0)
	{
		strtmp = charmultip(result[0], power("5", -exponent));
		tmp0 += -exponent;
		tmp1 = -exponent - (ft_strlen(strtmp) - ft_strlen(result[0]));
		tmp2 = -404;
	}
	if (result[0])
		free(result[0]);
	minimize_error(&strtmp, precision, ft_strlen(strtmp) - 1, 0);
	e_sci_fi(&strtmp, tmp1, tmp2);
	return (strtmp);
}

char	*e_floaki(long double fl, int precision, int bolpoint)
{
	char		*result;
	t_floaki	floaki;
	char		*strtmp;
	int			exponent;

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
		result = e_floakii(&result, exponent, precision);
		result = addpoint(result, 1, bolpoint, floaki.parts.sign);
		return (result);
	}
	return (e_floaki_s_cases(exponent, precision, floaki.parts.sign, bolpoint));
}
