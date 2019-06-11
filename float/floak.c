/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:48:50 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/11 14:07:30 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./floak.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	s_strjoin_frii(char **s1, char **s2, char **joinresult, int a)
{
	if (joinresult[0])
		free(joinresult[0]);
	if (a == 0)
	{
		free(s1[0]);
		free(s2[0]);
	}
	else if (a == 1)
		free(s1[0]);
	else if (a == 2)
		free(s2[0]);
}

void	s_strjoin(char **s1, char **s2, char **joinresult, int a)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*join;

	if (s1[0] == NULL || s2[0] == NULL)
		return ;
	i = 0;
	len1 = ft_strlen(s1[0]);
	len2 = ft_strlen(s2[0]);
	join = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
	if (join == NULL)
		return ;
	join[len1 + len2] = '\0';
	while (i < len1 + len2)
	{
		if (i < len1)
			join[i] = s1[0][i];
		else
			join[i] = s2[0][i - len1];
		i++;
	}
	s_strjoin_frii(s1, s2, joinresult, a);
	joinresult[0] = join;
}

void	rm_uzeros(char **str)
{
	int		i;
	char	*strtmp;

	i = 0;
	if (str[0][0] != '0')
	{
		strtmp = ft_strdup(str[0]);
		free(str[0]);
		str[0] = strtmp;
		return ;
	}
	while (str[0][i] == '0')
		i++;
	strtmp = ft_strsub(str[0], i, ft_strlen(str[0]) - i);
	free(str[0]);
	str[0] = strtmp;
}

char	*add_zeros(char **str1, char **str2, char **cnststr1, char **cnststr2)
{
	char	*strtmp;
	char	*str;
	int		m;

	str1[0] = NULL;
	str2[0] = NULL;
	str = NULL;
	m = ft_strlen(cnststr1[0]) - ft_strlen(cnststr2[0]);
	if (m == 0)
	{
		str1[0] = cnststr1[0];
		str2[0] = cnststr2[0];
		str = ft_memalloc(ft_strlen(cnststr1[0]) + 2);
		return (str);
	}
	strtmp = (char*)malloc(sizeof(char) * (m + 1));
	strtmp[m] = '\0';
	while (m)
		strtmp[--m] = '0';
	s_strjoin(&strtmp, cnststr2, str2, 1);
	str1[0] = cnststr1[0];
	str = ft_memalloc(ft_strlen(cnststr1[0]) + 2);
	return (str);
}

char	*charsum(char *cnststr1, char *cnststr2)
{
	char	*str;
	char	*str1;
	char	*str2;
	int		t[3];

	t[2] = 0;
	if ((t[0] = ft_strlen(cnststr1)) - ft_strlen(cnststr2) > 0)
		str = add_zeros(&str1, &str2, &cnststr1, &cnststr2);
	else if ((t[0] = ft_strlen(cnststr2)))
		str = add_zeros(&str2, &str1, &cnststr2, &cnststr1);
	else
		return (NULL);
	t[0]--;
	while (t[0] + 1)
	{
		t[1] = ((str1[t[0]] - '0') + (str2[t[0]] - '0') + t[2]) % 10;
		t[2] = (((str1[t[0]] - '0') + (str2[t[0]] - '0') + t[2])) / 10;
		str[t[0]-- + 1] = t[1] + '0';
		if (t[0] == -1 && t[2])
			str[0] = t[2] + '0';
	}
	if (str[0] == '\0')
		str[0] = '0';
	rm_uzeros(&str);
	return (str);
}

void	multip(char *str0, char *str1, char **str, int *t)
{
	int tmp2;
	int k;
	int x;
	int y;

	while (t[0] + 1)
	{
		tmp2 = t[1];
		k = t[0] + tmp2 + 1;
		y = 0;
		x = 0;
		while (tmp2 + 1)
		{
			x = (((str0[t[0]] - '0') * (str1[tmp2] - '0'))
					+ y + (str[0][k] - '0')) % 10;
			y = ((str0[t[0]] - '0') * (str1[tmp2] - '0')
					+ y + (str[0][k] - '0')) / 10;
			str[0][k] = x + '0';
			tmp2--;
			k--;
			if (tmp2 + 1 == 0 && y)
				str[0][k] = y + '0';
		}
		t[0]--;
	}
}

char	*charmultip(char *str0, char *str1)
{
	char	*str;
	int		x;
	int		t[2];
	int		k;

	x = 0;
	t[0] = ft_strlen(str0) - 1;
	t[1] = ft_strlen(str1) - 1;
	k = t[0] + t[1] + 1;
	str = (char*)malloc(sizeof(char) * (k + 2));
	str[k + 1] = '\0';
	while (x < k + 1)
		str[x++] = '0';
	multip(str0, str1, &str, t);
	rm_uzeros(&str);
	return (str);
}

char	*power(char *str, int times)
{
	char *strtmp;
	char *strtmpp;

	strtmpp = ft_memalloc(2);
	strtmpp[0] = '1';
	if (times == 0)
		return (strtmpp);
	free(strtmpp);
	strtmpp = ft_strdup(str);
	while (times - 1 > 0)
	{
		strtmp = charmultip(strtmpp, str);
		free(strtmpp);
		strtmpp = strtmp;
		times--;
	}
	return (strtmpp);
}

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
	strtmp[0] = (sign) ? '-' : '+';
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

int			pf_bug(char *str, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] - '0' > 0)
			return (1);
		i++;
	}
	return (0);
}

int		rm_sgnfc_nbrs(char **str, int a_lastpos, int precision)
{
	char	*strtmp;
	int		condition;
	int		incrmntlen;

	condition = 0;
	incrmntlen = 0;
	if (str[0][a_lastpos] > '5' ||
			(a_lastpos > 0 && str[0][a_lastpos - 1] % 2 == 1
			 && str[0][a_lastpos] == '5') || (precision == 0 && a_lastpos > 0
				 && str[0][a_lastpos] == '5' &&
				 (str[0][a_lastpos - 1] - '0') % 2 == 0 &&
				 pf_bug(str[0], a_lastpos + 1)))
		condition = 1;
	strtmp = ft_strsub(str[0], 0, a_lastpos);
	free(str[0]);
	str[0] = strtmp;
	incrmntlen = ft_strlen(str[0]);
	if (condition)
	{
		strtmp = charsum(str[0], "1");
		free(str[0]);
		str[0] = strtmp;
	}
	incrmntlen = ft_strlen(str[0]) - incrmntlen;
	return (incrmntlen);
}

void		lack_sgnfc_nmbrs(char **str, int nintprtlen, int precision)
{
	int		tmp;
	char	*strtmp;

	tmp = nintprtlen;
	tmp = precision - tmp;
	strtmp = ft_memalloc(tmp + 1);
	while (--tmp >= 0)
		strtmp[tmp] = '0';
	s_strjoin(str, &strtmp, str, 2);
}

void	dev_str_byten(char **str, int p_mten, int precision, int a_lastpos)
{
	char	*strtmp;

	if (p_mten > precision)
		p_mten = precision + 1;
	strtmp = ft_memalloc(p_mten + 1);
	while (--p_mten >= 0)
		strtmp[p_mten] = '0';
	if (a_lastpos >= 0)
		s_strjoin(&strtmp, &str[0], &str[0], 1);
	else
	{
		free(str[0]);
		str[0] = strtmp;
	}
}

void	minimize_error(char **str, int prec, int nintprtlen, int pminusten)
{
	int		a_lastpos;
	char	*strtmp;
	int		condition;
	int		incrmntlen;

	incrmntlen = 0;
	if (pminusten > 0)
		a_lastpos = prec - (pminusten - 1);
	else
		a_lastpos = ft_strlen(str[0]) - nintprtlen + prec;
	condition = 0;
	if (nintprtlen > prec && a_lastpos >= 0)
		incrmntlen = rm_sgnfc_nbrs(str, a_lastpos, prec);
	else if (nintprtlen < prec && a_lastpos >= 0)
		lack_sgnfc_nmbrs(str, nintprtlen, prec);
	if (pminusten > 0)
	{
		pminusten = pminusten - incrmntlen;
		dev_str_byten(str, pminusten, prec, a_lastpos);
	}
}

void	pmten_decmantissa(char **result, int i)
{
	int		tmp0;
	char	*strtmp2;

	if (i > 0)
	{
		tmp0 = ft_strlen(result[0]);
		//while (result[0][tmp0] == '0')
		//	tmp0--;
		tmp0 = i - tmp0;
		if (tmp0 > 0)
		{
			strtmp2 = ft_memalloc(tmp0 + 1);
			tmp0--;
			while(tmp0 >= 0)
			{
				strtmp2[tmp0] = '0';
				tmp0--;
			}
			s_strjoin(&strtmp2, result, result, 1);
		}
	}
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
			strtmp2 = power("5", i + 1);
			result[0] = charsum(strtmpp, strtmp2);
			s_strjoin(result, &zerostr, &strtmpp, 404);
			free(strtmp2);
		}
		else
			s_strjoin(&strtmpp, &zerostr, &strtmpp, 404);
		i++;
		floaki.parts.mantisa = floaki.parts.mantisa << 1;
	}
	pmten_decmantissa(result, i);
}

char	*infinity(int sign)
{
	char *result;

	if (sign)
		result = ft_strdup("-inf");
	else
		result = ft_strdup("+inf");
	return (result);
}

char	*nani(void)
{
	char *result;

	result = ft_strdup("nan");
	return (result);
}

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
