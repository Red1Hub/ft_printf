/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmahjoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 19:55:13 by rmahjoub          #+#    #+#             */
/*   Updated: 2018/10/09 03:54:37 by rmahjoub         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *h, const char *needle)
{
	int		i;
	int		j;
	char	*tmp;

	j = 0;
	i = 0;
	tmp = (char*)h;
	if (needle[0] == '\0')
		return (tmp);
	while (h[i] != '\0')
	{
		if (h[i] == needle[0])
		{
			while (h[i + j] == needle[j] && h[i] != '\0')
			{
				j++;
				if (needle[j] == '\0')
					return (tmp + i);
			}
		}
		i++;
	}
	return (NULL);
}
