/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arithmtics.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:17:23 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/13 15:41:20 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

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
		str1[0] = ft_strdup(cnststr1[0]);
		str2[0] = ft_strdup(cnststr2[0]);
		str = ft_memalloc(ft_strlen(cnststr1[0]) + 2);
		return (str);
	}
	strtmp = (char*)malloc(sizeof(char) * (m + 1));
	strtmp[m] = '\0';
	while (m)
		strtmp[--m] = '0';
	s_strjoin(&strtmp, cnststr2, str2, 1);
	str1[0] = ft_strdup(cnststr1[0]);
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
	rm_uzeros_charsum(&str, &str1, &str2);
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
