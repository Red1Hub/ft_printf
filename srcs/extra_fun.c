/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_fun.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:03:13 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/12 16:47:03 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int		ltrtobs(char c)
{
	if (c == 'x' || c == 'X')
		return (16);
	if (c == 'u' || c == 'd' || c == 'i')
		return (10);
	if (c == 'o')
		return (8);
	return (0);
}

int		strtablechr(int *taba, int x)
{
	int i;
	int j;

	i = 0;
	while (taba[i] != cantor('0', '0'))
	{
		if (taba[i] == x)
			return (1);
		i++;
	}
	return (0);
}

int		cantor(int a, int b)
{
	return ((a + b) * (a + b + 1) + b);
}

int		strchrchr(char *stringa, char *stringb, char c)
{
	int i;
	int j;

	i = 0;
	while (stringa[i] != '\0')
	{
		if (stringa[i] == c)
		{
			j = 0;
			while (stringb[j] != '\0')
				if (stringb[j++] == c)
					return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

char	*str_sub_digit(char **str, t_printfv *printfv)
{
	int		i;
	char	*tmp;
	char	*tmp0;

	i = 0;
	while (str[0][i] != '\0' && (str[0][i] == ' ' ||
				str[0][i] == 'X' || str[0][i] == 'x' ||
				str[0][i] == '+' || str[0][i] == '-' ||
				(str[0][i] == '0' && i == 0 && (str[0][1] == 'x' ||
												str[0][1] == 'X')
				&& printfv->percent.hash
				&& strchrchr("oxXp", "\0", printfv->percent.specifier))))
		i++;
	if (i)
		tmp0 = ft_strsub(*str, 0, i);
	else
		tmp0 = NULL;
	tmp = ft_strsub(*str, i, ft_strlen(*str) - i);
	ft_memdel((void**)str);
	*str = tmp;
	return (tmp0);
}
