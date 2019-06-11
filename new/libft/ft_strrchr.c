/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:44:01 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/11 00:24:47 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		k;
	char	*tmp;

	tmp = (char*)s;
	k = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			k = i;
		i++;
	}
	if (c == '\0')
		return (tmp + i);
	tmp = tmp + k;
	if (k != -1)
		return (tmp);
	return (NULL);
}
