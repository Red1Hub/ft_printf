/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 17:01:18 by rmahjoub          #+#    #+#             */
/*   Updated: 2019/06/12 19:45:26 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

char	*ft_itoa_base_ll(long long int x)
{
	long long int	tmp;
	int				base;
	int				i;
	char			*str;

	i = 0;
	base = 10;
	x = -x;
	tmp = x;
	while (tmp > 0 && ++i)
		tmp = tmp / base;
	str = (char*)malloc(sizeof(char) * (i + 2));
	str[i + 1] = '\0';
	str[0] = '-';
	while (i > 0)
	{
		if (x % base < 10)
			str[--i + 1] = x % base + '0';
		x = x / base;
	}
	return (str);
}

char	*itoa_shandler(long long x, int condition, int precision0)
{
	char *str;

	if (x == -9223372036854775807 - 1 && condition)
	{
		str = ft_strdup("-9223372036854775808");
		return (str);
	}
	if (x == 0)
	{
		if (precision0)
		{
			str = ft_memalloc(2);
			str[0] = '+';
			return (str);
		}
		str = ft_strdup("+0");
		return (str);
	}
	return (NULL);
}

void	ft_itoa_fill(char *str, unsigned long long x, int b, char c)
{
	int					i;
	unsigned long long	tmp;

	i = 0;
	tmp = x;
	while (tmp > 0 && ++i)
		tmp = tmp / b;
	while (i > 0)
	{
		if (x % b < 10)
			str[i] = x % b + '0';
		else if (c < 'a')
			str[i] = 'A' + x % b - 10;
		else
			str[i] = 'a' + x % b - 10;
		x = x / b;
		i--;
	}
}

char	*ft_itoa_base(unsigned long long x, int b, char c, t_printfv *printfv)
{
	int					i;
	int					sign;
	unsigned long long	tmp;
	char				*str;

	if ((str = itoa_shandler((long long)x,
					(c != 'u' && b == 10), printfv->percent.precision0)))
		return (str);
	i = 0;
	sign = 0;
	if ((long long int)x < 0 && b == 10 && c != 'u' && (sign = 1))
		return (ft_itoa_base_ll((long long int)x));
	tmp = x;
	while (tmp > 0 && ++i)
		tmp = tmp / b;
	str = (char*)malloc(sizeof(char) * (i + 2));
	str[i + 1] = '\0';
	str[0] = '+';
	ft_itoa_fill(str, x, b, c);
	return (str);
}
