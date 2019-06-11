/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   popo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:48:50 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/03 01:23:50 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "./floak.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	s_strjoin(char **s1, char **s2, char **joinresult, int a)
{
	size_t	i;
	size_t	len1;
	size_t	len2;
	char	*join;

	//if (join && s1[0] != join[0])
	//	free(join[0]);
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
	if (joinresult[0])
	{
		free(joinresult[0]);
	}
	joinresult[0] = join;
	
	if (a == 0)
	{
		free(s1[0]);
		free(s2[0]);
	}
	else if(a == 1)
		free(s1[0]);
	else if(a == 2)
		free(s2[0]);
}

char	*rm_uzeros(char *str)
{
	int i;

	i = 0;
	if (str[0] != '0')
		return(ft_strdup(str));
	while (str[i] == '0')
		i++;
	return (ft_strsub(str, i, ft_strlen(str) - i));
}

char	*charsum(char *cnststr1, char *cnststr2)
{
	char 	*str;
	char 	*str1;
	char 	*str2;
	char	*strtmp;
	int i;
	int j;
	int x;
	int y;
	int z;
	int m;
	int tmp;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	str = NULL;
	str1 = NULL;
	str2 = NULL;
	if ((m = ft_strlen(cnststr1) - ft_strlen(cnststr2)) > 0)
	{
		str1 = (char*)malloc(sizeof(char) * (m + 1));
		str1[m] = '\0';
		while (m)
			str1[--m] = '0';
		s_strjoin(&str1, &cnststr2, &str2, 1);
		str1 = cnststr1;
		str = ft_memalloc(ft_strlen(cnststr1) + 2);
		tmp = ft_strlen(cnststr1);
	}
	else if (m < 0)
	{
		m = -m;
		str2 = (char*)malloc(sizeof(char) * (m + 1));
		str2[m] = '\0';
		while (m)
			str2[--m] = '0';
		s_strjoin(&str2, &cnststr1, &str1, 1);
		str2 = cnststr2;
		str = ft_memalloc(ft_strlen(cnststr2) + 2);
		tmp = ft_strlen(cnststr2);
	}
	else
	{
		str1 = cnststr1;
		str2 = cnststr2;
		str = ft_memalloc(ft_strlen(cnststr1) + 2);
		tmp = ft_strlen(cnststr1);
	}
	i = ft_strlen(str1) - 1;
	while (i + 1)
	{
		x = ((str1[i] - '0') + (str2[i] - '0') + y) % 10;
		str[tmp--] = x + '0';
		y = (((str1[i] - '0') + (str2[i] - '0') + y)) / 10;
		if (i == 0 && y)
			str[tmp--] = y + '0';
		i--;
	}
	while (tmp + 1)
		str[tmp--] = '0';
	strtmp = rm_uzeros(str);
	free (str);
	str = strtmp;
	return (str);
}

char	*charmultip(char *str0, char *str1)
{
	char *str;
	char *strtmp;
	int x;
	int y;
	int tmp0;
	int tmp1;
	int	tmp2;
	int k;

	x = 0;
	y = 0;
	tmp0 = ft_strlen(str0) - 1;
	tmp1 = ft_strlen(str1) - 1;
	k = tmp0 + tmp1 + 1;
	
	str = (char*)malloc(sizeof(char) * (k + 2));
	str[k + 1] = '\0';
	while (x < k + 1)
		str[x++] = '0';
	x = 0;
	
	tmp2 = tmp1;
	while (tmp0 + 1)
	{
		tmp1 = tmp2;
		k = tmp0 + tmp1 + 1;
		y = 0;
		x = 0;
		while (tmp1 + 1)
		{
			x = (((str0[tmp0] - '0') * (str1[tmp1] - '0')) + y + (str[k] - '0')) % 10;
			y = ((str0[tmp0] - '0') * (str1[tmp1] - '0') + y + (str[k] - '0')) / 10;
			str[k] = x + '0';
			tmp1--;
			k--;
			if (tmp1 + 1 == 0 && y)
				str[k] = y + '0';
		}
		tmp0--;
	}
	strtmp = rm_uzeros(str);
	free(str);
	return(strtmp);
}

char	charmultip(char	*str0, char *str1)
{
	int	 	i;
	int 	j;
	char 	str;

	i = 0;
	j = 0;
	while (str0[i] != '\0')
	{
		if (str0[i] == '.')
		{
			i++;
			break;
		}
		i++;
	}
	while (str1[j] != '\0')
	{
		if (str1[j] == '.')
		{
			j++;
			break;
		}
		j++;
	}
	charmultip(str0 + i, str1 + j);
	if (i + j)
	{
		str = (char*)malloc(sizeof(char) * (i + j + 1));
		str[i + j] = '\0';
		while (i + j)
	}
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

char	*addpoint(char **str, int pos)
{
	char	*strtmp;
	int		i;
	int 	len;

	i = 0;
	len = ft_strlen(str[0]);
	strtmp = ft_memalloc(len + 2);
	while (i < pos)
	{
		strtmp[i] = str[0][i];
		i++;
	}
	strtmp[i] = '.';
	while (i < len)
	{
		strtmp[i + 1] = str[0][i];
		i++;
	}
	ft_memdel((void**)str);
	return (strtmp);
}

void		minimize_error(char **str, int precision, int nintprtlen, int pminusten)
{
	int tmp;
	int tmp0;
	char *strtmp;
	int condition;
	int len;


	tmp = nintprtlen;
	len = 0;
	tmp0 = precision - (pminusten - 1);
	condition = 0;

	if (nintprtlen > precision && tmp0 >= 0)
	{
		if (str[0][tmp0] > '5')
			condition = 1;
		//ft_putchar(str[0][tmp0]);
		//getchar();
		strtmp = ft_strsub(str[0], 0, tmp0);
		free(str[0]);
		str[0] = strtmp;
		len = ft_strlen(str[0]);
		if (condition)
		{
			strtmp = charsum(str[0], "1");
			free(str[0]);
			str[0] = strtmp;
		}
		len = len - ft_strlen(str[0]);
	}
	else if (nintprtlen < precision && tmp0 >= 0)
	{
		tmp = precision - tmp;
		strtmp = ft_memalloc(tmp + 1);
		while (--tmp >= 0)
			strtmp[tmp] = '0';
		//ft_putstr(str[0]);
		//ft_putstr(strtmp);
		s_strjoin(str, &strtmp, str, 2);
		//free(strtmp);
	}
	if (pminusten > 0)
	{
		pminusten = pminusten - len;
		if (pminusten > precision)
			pminusten = precision + 1;
		strtmp = ft_memalloc(pminusten + 1);
		while (--pminusten >= 0)
			strtmp[pminusten] = '0';
		if (tmp0 >= 0)
			s_strjoin(&strtmp, &str[0], &str[0], 1);
		else
		{
			free(str[0]);
			str[0] = strtmp;
		}
	}
}

void	decimal_mantissa(char **result, long double fl, int precision)
{
	t_floaki	floaki;
	int 			i;
	char			*strtmpp;
	char			*strtmp2;
	int				k;
	char			*zerostr;
	int				tmp0;

	k = 0;
	zerostr = ft_memalloc(2);
	zerostr[0] = '0'; // recently modified in case of errors
	floaki.f = fl;
	i = 0;
	strtmpp = ft_memalloc(2);
	strtmpp[0] = '0';
	while (floaki.parts.mantisa > 0)
	{
		if (floaki.parts.mantisa & 0x4000000000000000)
		{
			if (result[0])
			{
				free(result[0]);
				result[0] = NULL;
			}
			strtmp2 = power("5", i + 1);
			result[0] = charsum(strtmpp, strtmp2);
			s_strjoin(result, &zerostr, &strtmpp, 3);
			free(strtmp2);
		}
		else
			s_strjoin(&strtmpp, &zerostr, &strtmpp, 4);
		i++;
		floaki.parts.mantisa = floaki.parts.mantisa << 1;
	}
	if (i > 0)
	{
		tmp0 = ft_strlen(result[0]);
		while (result[0][tmp0] == '0')
			tmp0--;
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

char	*infinity()
{
	char *result;

	result = ft_memalloc(4);
	result[0] = 'i';
	result[1] = 'n';
	result[2] = 'f';
	return(result);
}

char	*NaN()
{
	char *result;

	result = ft_memalloc(4);
	result[0] = 'N';
	result[1] = 'a';
	result[2] = 'N';
	return(result);
}

void	sign(char **result, int sign)
{
	char *minus;

	minus = ft_memalloc(2);
	if (sign)
		minus[0] = '-';
	else
		minus[0] = '+';
	s_strjoin(&minus, result, result, 1);
}

char	*floaki(long double fl, int precision)
{
	char 		*result;
	t_floaki 	floaki;
	char		*strtmp;
	int			exponent;
	int			tmp0;
	int			tmp1;
	char		*zerostr;

	tmp1 = 0;
	tmp0 = 0;
	floaki.f = fl;
	zerostr = ft_memalloc(2);
	zerostr[0] = '0';
	exponent = floaki.parts.exponent - 16383;
	result = NULL;
	decimal_mantissa(&result, fl, precision);
	if (floaki.parts.mantisa)
	{
		if (exponent == 1024)
		{
			return(NaN());
		}
		tmp0 = ft_strlen(result);
		strtmp = ft_strjoin("1", result);
		free(result);
		result = strtmp;
		if (exponent >= 0)
			strtmp = charmultip(result, power("2", exponent));
		else if (exponent < 0)
		{
			strtmp = charmultip(result, power("5", -exponent));
			tmp0 += -exponent;
			tmp1 = -exponent - (ft_strlen(strtmp) - ft_strlen(result));

		}
		free(result);
		result = strtmp;
		minimize_error(&result, precision, tmp0, tmp1);
		if (precision != 0)
			result = addpoint(&result, ft_strlen(result) - precision);
		sign(&result, floaki.parts.sign);
		return(result);
	}
	if (exponent + 16383 == 0)
	{
		result = zerostr;
		minimize_error(&result, precision, 0, -1);
		result = addpoint(&result, 1);
		sign(&result, floaki.parts.sign);
		return (result);
	}
	if (exponent == 16384)
		return(infinity());
	free(zerostr);
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
	result = addpoint(&result, ft_strlen(result) - precision);
	sign(&result, floaki.parts.sign);
	return (result);
}


#include <limits.h>
#include <float.h>
int main()
{
	int x;
	char *strtmp0;
	char *str;

	x = 0;

	 //  strtmp0 = ft_itoa(x);
	  // ft_putstr(strtmp0);
	 //  ft_putstr("\n");
	 //  ft_putstr(ft_itoa(x));
	
	//str = charmultip("22", "11");
	//ft_putstr(power("5", 16382));
	str = floaki(DBL_MAX, 1);
	//str = ft_strjoin("1", str);
	ft_putstr(str);
	ft_putchar('\n');
	ft_putnbr(ft_strlen(str));
	ft_putchar('\n');
	//ft_putstr(charmultip("422", "44"));
	//ft_putstr(str);
	//ft_putchar('\n');
	//ft_putstr(power("2", 55));
	ft_putnbr(printf("\n%.100f\n", DBL_MAX));

	//ft_putstr(charsum("0000004", "000000"));
	//strtmp0 = NULL;
	//ft_realloc(&strtmp0, 0);
	//ft_putstr("kkkkkkkkkkkkk\n");
	//ft_putstr(ft_itoa(0));
	return (0);
}
