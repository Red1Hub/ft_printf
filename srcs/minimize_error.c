/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimize_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 15:13:26 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/12 13:43:45 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		pf_bug(char *str, int i)
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
			(str[0][a_lastpos] == '5' && pf_bug(str[0], a_lastpos + 1)) ||
			(a_lastpos > 0 && (str[0][a_lastpos - 1] - '0') % 2 == 1
			&& str[0][a_lastpos] == '5' && precision == 0))
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

void	lack_sgnfc_nmbrs(char **str, int nintprtlen, int precision)
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
