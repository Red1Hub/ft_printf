/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 11:28:43 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/13 10:24:08 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_result(int len, long n, int k)
{
	int		j;
	char	*itoa;

	j = 0;
	itoa = (char*)malloc(sizeof(char) * (len + 1 + k));
	if (itoa == NULL)
		return (NULL);
	itoa[len + k] = '\0';
	while (j < len - 1)
	{
		itoa[len - 1 - j + k] = n % 10 + 48;
		j++;
		n = n / 10;
	}
	itoa[k] = n + 48;
	if (k == 1)
		itoa[0] = '-';
	return (itoa);
}

char		*ft_itoa(int n)
{
	long	tmp;
	int		len;
	int		k;

	k = 0;
	tmp = (long)n;
	len = 0;
	if (tmp < 0)
	{
		k = 1;
		tmp = -tmp;
		n = (int)(tmp - k);
	}
	while (tmp > 0)
	{
		tmp = tmp / 10;
		len++;
	}
	tmp = (long)n + k;
	return (ft_result(len, tmp, k));
}
